/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

/** This is a C prototype for the assmbly lanague function
    defined in asm-02.s. */
int addThree( int a, int b, int c );

int main()
{
  int total = addThree( 702, 496, 825 );
  printf( "%d\n", total );
  
  return EXIT_SUCCESS;
}
