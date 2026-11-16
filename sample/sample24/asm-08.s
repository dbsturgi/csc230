### This program demonstrates how a switch statement is implemented with a jump
### table.
    
### Build with the following compile commands, either on the common platform
### or using the -no-pie option for newer systems.

### gcc prog-08.c asm-08.s -o prog-08
### gcc -no-pie prog-08.c asm-08.s -o prog-08

    ## Expose the name of our subroutine.
    .global letterScore

    ## Code goes in the text section.
    .text

    ## Jump table implementation.  This is a good example of data that could
    ## go in the text section.  It doesn't need to change during execution.
JTABLE:
    ## Score fo zero for everything up to the first letter.
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0

    ## These are the capital letters.
    .quad SCORE_0, SCORE_1, SCORE_3, SCORE_3, SCORE_4, SCORE_1, SCORE_4, SCORE_2
    .quad SCORE_4, SCORE_1, SCORE_8, SCORE_5, SCORE_1, SCORE_3, SCORE_1, SCORE_1
    .quad SCORE_3, SCORE_A, SCORE_1, SCORE_1, SCORE_1, SCORE_1, SCORE_4, SCORE_4
    .quad SCORE_8, SCORE_4, SCORE_A, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0

    ## These are the lower-case ones.
    .quad SCORE_0, SCORE_1, SCORE_3, SCORE_3, SCORE_4, SCORE_1, SCORE_4, SCORE_2
    .quad SCORE_4, SCORE_1, SCORE_8, SCORE_5, SCORE_1, SCORE_3, SCORE_1, SCORE_1
    .quad SCORE_3, SCORE_A, SCORE_1, SCORE_1, SCORE_1, SCORE_1, SCORE_4, SCORE_4
    .quad SCORE_8, SCORE_4, SCORE_A, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0

    ## Score of zero for all the other possible character codes.
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0
    .quad SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0, SCORE_0

### This is an implementation of the C function, except the assembly code
### works for capital or lower-case.
### int letterScore( char let )
### {
###   switch ( let ) {
###   case 'q':
###   case 'z':
###     return 10;
###         
###   case 'j':
###   case 'x':
###     return 8;
###         
###   case 'k':
###     return 5;
###         
###   case 'f':
###   case 'h':
###   case 'v':
###   case 'w':
###   case 'y':
###     return 4;
###         
###   case 'b':
###   case 'c':
###   case 'm':
###   case 'p':
###     return 3;
###         
###   case 'd':
###   case 'g':
###     return 2;
###         
###   case 'a':
###   case 'e':
###   case 'i':
###   case 'l':
###   case 'n':
###   case 'o':
###   case 'r':
###   case 's':
###   case 't':
###   case 'u':
###     return 1;
###
###   default:
###     return 0;
###   }
### }
letterScore:
    ## This example doesn't need a stack frame.  We don't use one so we can
    ## keep the return code simple.

    movq    $0, %rax            # Clear all of rdx
    mov     %dil, %al           # Copy a byte-sized parameter.
    imul    $8, %rax            # Multiply by 8 (8 bytes per element)

    movq    JTABLE(%rax), %rax  # Get the element of the table.

    jmp     *%rax               # Jump to that address.

SCORE_A:
    movl    $10, %eax           # Give a score of 10
    ret                         # Return to the caller.
    
SCORE_8:
    movl    $8, %eax            # Give a score of eight
    ret                         # Return to the caller.
    
SCORE_5:
    movl    $5, %eax            # Give a score of five
    ret                         # Return to the caller.
    
SCORE_4:
    movl    $4, %eax            # Give a score of four
    ret                         # Return to the caller.
    
SCORE_3:
    movl    $3, %eax            # Give a score of three
    ret                         # Return to the caller.
    
SCORE_2:
    movl    $2, %eax            # Give a score of two
    ret                         # Return to the caller.
    
SCORE_1:
    movl    $1, %eax            # Give a score of one
    ret                         # Return to the caller.
    
SCORE_0:
    movl    $0, %eax            # Give a score of zero
    ret                         # Return to the caller.
