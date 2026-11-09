### Empty function that can be called from C.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-01.c asm-01.s -o prog-01
### gcc -no-pie prog-01.c asm-01.s -o prog-01

    ## The name of our subroutine needs to be visible to the linker.
    .global myFunction

    ## Code goes in the text section.
    .text

### A function that returns right away.
myFunction:
    ret                             # Return to the caller.
