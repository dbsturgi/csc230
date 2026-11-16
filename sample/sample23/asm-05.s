### This demonstrates asccessing array elements using base register mode.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-05.c asm-05.s -o prog-05
### gcc -no-pie prog-05.c asm-05.s -o prog-05

    ## Expose the name of our subroutine.
    .global sumElements

    ## Code goes in the text section.
    .text

### Takes an array of ints and a length.  Adds up all
### the ints and returns the sum.
sumElements:      
    ## This funcitond doesn't really need it, but we go through the
    ## steps of setting up a stack frame here.
    
    push    %rbp                # Save a copy of the base pointer
    mov     %rsp, %rbp          # Base points to a fixed stack location.

    mov     $0, %eax            # Clear the return value.

    ## Loop over all the array elements.
start:                
    cmp     $0, %esi            # Compare the loop counter against zero.
    jle     done                # Bail out when we hit zero.

    add     (%rdi), %eax        # Add the next element to the sum.

    add     $4, %rdi            # Move ahead to the next element
    dec     %esi                # Decrement the loop counter.

    jmp     start               # Jump back to the top of the loop
done:       

    pop     %rbp                # Restore the base pointer
    ret                         # Return to the caller.
