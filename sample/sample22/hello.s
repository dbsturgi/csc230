### Program to print out Hello World.
### You can compile it on the common platform with:
### gcc hello.s -o hello

### On a newer system, you may need the -no-pie link option.
### gcc -no-pie hello.s -o hello

    ## The start symbol is global.  It's viible to other code
    ## that gets linked with this program.
    .global main

    ## This is the text section of the program.  That's where
    ## executable code and read-only data goes.
    .text
    
message:
    ## This is a literal string, with a null terminator at the end.
    .asciz  "Hello World."

### This label says where main starts in our program.
main:
    ## Call to puts( "Hello World." );
    mov     $message, %rdi          # Address of missage is the parameter.
    call    puts                    # Call puts()
    ret                             # Return from main.
