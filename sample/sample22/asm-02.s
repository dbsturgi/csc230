### This demonstrates C parameter passing and return values.
### The addThree() function takes three integer parameters and returns
### their sum.

### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-02.c asm-02.s -o prog-02
### gcc -no-pie prog-02.c asm-02.s -o prog-02

    ## Expose the name of our subroutine.
    .global addThree

    ## Code goes in the text section.
    .text

### Add up the values of three integer parameters.
addThree:
    mov     %edi, %eax          # Copy first parameter to the return value.
    add     %esi, %eax          # Add second parameter to the return value.
    add     %edx, %eax          # Add third parameter to the return value.
    ret                         # Return to the caller.
