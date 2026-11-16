### This program demonstrates accessing fields of a struct using base
### plus displacement addressing.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-06.c asm-06.s -o prog-06
### gcc -no-pie prog-06.c asm-06.s -o prog-06

    ## Expose the name of our subroutine.
    .global initStruct

    ## Code goes in the text section.
    .text

### Put something in all the fields of a struct.
initStruct: 
    ## This funcitond doesn't really need it, but we go through the
    ## steps of setting up a stack frame here.
    
    push    %rbp                # Save a copy of the base pointer
    mov     %rsp, %rbp          # Base points to a fixed stack location.

    movb    $'z', 0(%rdi)       # put a z in field a (1 byte)
    movl    $100, 4(%rdi)       # put 100 in field b (4 bytes)
    movw    $25, 8(%rdi)        # put 25 in field c (2 bytes)

    pop     %rbp                # Restore the base pointer
    ret                         # Return to the caller.
