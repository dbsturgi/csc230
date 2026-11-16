### This demonstrates a loop in assembly language, using edx as the loop control
### variable.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-04.c asm-04.s -o prog-04
### gcc -no-pie prog-04.c asm-04.s -o prog-04

    ## Expose the name of our subroutine.
    .global add1to10

    ## Code goes in the text section.
    .text

### A loop counting down from 10 to 1.
add1to10:      
    ## This funcitond doesn't really need it, but we go through the
    ## steps of setting up a stack frame here.
    
    push    %rbp                # Save a copy of the base pointer
    mov     %rsp, %rbp          # Base points to a fixed stack location.

    mov     $0, %eax            # clear out the sum stored in eax.
    mov     $10, %edx           # edx is our loop counter, start at 10.
start:
    cmp     $0, %edx            # Compare loop coutner to 0
    je      done                # Jump out of loop if it's 0
    
    add     %edx, %eax          # Accumulate a sum

    dec     %edx                # Decrement the loop counter.
    jmp     start               # Jump back to the start of the loop.
done:

    pop     %rbp                # Restore the base pointer
    ret                         # Return to the caller.
