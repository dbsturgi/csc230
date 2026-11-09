### This demonstrates accessing C symbols from assembly language.
### It's easy.  We can see any symbol name exposed to the linker.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-03.c asm-03.s -o prog-03
### gcc -no-pie prog-03.c asm-03.s -o prog-03

    ## Expose the name of our subroutine.
    .global addGlobals

    ## Code goes in the text section.
    .text

### Add two global variables and return the result.
addGlobals:      

    mov     globalA, %eax       # Copy one of them to eax
    add     globalB, %eax       # Add in the other

    ## We prepared the result in eax, so it's ready to
    ## return.

    ret                         # Return to the caller.
