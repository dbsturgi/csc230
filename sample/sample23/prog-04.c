/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

/** This is a C prototype for the assmbly lanague function
    defined in asm-04.s. */
int add1to10();

int main()
{
  // Call our function and print the value it returns.
  int x = add1to10();
  printf( "result: %d\n", x );
  
  return EXIT_SUCCESS;
}
