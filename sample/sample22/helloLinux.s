### Program to print out Hello World by making calls
### to the Linux operating system, so it's not portable
### to other OSs.

### You can compile it on the common platform with:
### gcc -nostdlib helloLinux.s -o helloLinux

### On a newer system, you may need -no-pie.
### gcc -nostdlib -no-pie helloLinux.s -o helloLinux

    ## Internall, progams really start at a label called _start.
    ## For a C program, this eventaully calls main.
    .global _start
    
    ## Start of the text section.
    .text
    
message:
    ## Characters to print out.  The OS just expects a sequence
    ## of bytes, so this doesn't need to be null terminated.
    .ascii  "Hello World.\n"

### Starting point for our program, before main gets called.
_start:
    ## OS call write( 1, message, 13 )
    mov     $1, %rdi                # file to write to (1st parameter)
    mov     $message, %rsi          # address of the message (2nd parameter)
    mov     $13, %rdx               # Write out 13 bytes (3rd parameter)
    mov     $1, %rax                # Ask for system call 1 (write)
    syscall                         # Jump to the OS
    
    ## OS call exit( 0 )
    mov     $0, %rdi                # exit status (0)
    mov     $60, %rax               # Ask for system call 60 (exit)
    syscall                         # Jump to the OS
    
    ## We never make it back from that last system call.
