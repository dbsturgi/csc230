/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

/** This is a C prototype for the assmbly lanague function
    defined in asm-03.s. */
int addGlobals();

// A couple of global variables for our assembly subroutine to
// access.
int globalA = 10;
int globalB = 20;
  
int main()
{
  // Call our function and see what it returns.
  int x = addGlobals( );
  printf( "result: %d\n", x );
  
  return EXIT_SUCCESS;
}
