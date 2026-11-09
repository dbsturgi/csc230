### Subroutines called from C.
    
### You should be able to compile this with each of the
### test programs to try out each of the functions.
    
    ## Expose the names of all of our subroutines.
    .global setGlobal

    ## Code goes in the text section.
    .text

### Implementation of setGlobal, assign 47 to a global variable.
setGlobal:
    # ...

    ret                         # Return to the caller.
    
### Implementation of swapGlobals, exchange the value of two global variables
swapGlobals:
    # ...

