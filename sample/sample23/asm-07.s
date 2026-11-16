### This program demonstrates using a couple of local variables, both of
### type int.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-07.c asm-07.s -o prog-07
### gcc -no-pie prog-07.c asm-07.s -o prog-07

    ## Expose the name of our subroutine.
    .global localVars

    ## Code goes in the text section.
    .text

    ## Format string for the scanf.
readFormat: 
    .asciz      "%d%d"

    ## Format string for the printf.
writeFormat:        
    .asciz      "Values: %d %d\n"

### This is an implementation of the C function:
### void localVars()
### {
###   int x = 0;
###   int y = 0;
###   scanf( "%d%d", &x, &y );
###   scanf( "Values: %d %d\n", x, y );
### }
localVars: 
    ## This example does need a stack frame, go throught he usual steps
    ## to set it up.
    
    push    %rbp                # Save a copy of the base pointer
    mov     %rsp, %rbp          # Base points to a fixed stack location.

    ## Here, we're making and initializing local variables x and y.
    
    ## Get 16 bytes of stack space.  We just need 8 bytes but this keeps
    ## the stack pointer 16-byte aligned.
    sub     $16, %rsp

    ## Put zeros in our two variables.  We don't really need to do this, but
    ## it helps to demonstrate where they are on the stack.
    movl    $0, -4(%rbp)        # x is 4 bytes before the base pointer.
    movl    $0, -8(%rbp)        # y is 4 bytes before the base pointer.

    ## Here, we're callng scanf( "%d%d", &x, &y );

    ## get the address of our format string into rdi.
    lea     readFormat, %rdi

    ## get the address of x into rsi, the 2nd parameter.
    lea     -4(%rbp), %rsi

    ## get the address of y into rdx, the 3rd parameter.
    lea     -8(%rbp), %rdx

    ## Varargs functions need a zero in eax
    mov     $0, %eax

    ## Make the call to scanf.  If successful, our local variables should
    ## get the values entered by the user.  Really, we should check the
    ## return value.
    call    scanf

    ## Here, we're calling printf( "Values: %d %d\n", x, y );

    ## get the address of our other format string into rdi.
    lea     writeFormat, %rdi

    ## get the value of x into esi, the 2nd parameter.
    mov     -4(%rbp), %esi

    ## get the value of y into edx, the 3rd parameter.
    mov     -8(%rbp), %edx

    ## Varargs functions need a zero in eax
    mov     $0, %eax

    ## Make the call to printf.
    call    printf

    ## Remove our local variables from the stack.
    add     $16, %rsp
    
    pop     %rbp                # Restore the base pointer
    ret                         # Return to the caller.
