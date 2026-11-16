/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

/** This is a C prototype for the assmbly lanague function
    defined in asm-05.s.  It adds up count items in the given
    array. */
int sumElements( int arr[], int count );

int main()
{
  // Make an array and determine its length.
  int list[] = { 7, 24, 3, 9, 11, 2, 16 };
  int len = sizeof( list ) / sizeof( list[ 0 ] );
  
  // Give the array and length to our assembly function.
  int sum = sumElements( list, len );
  printf( "sum: %d\n", sum );
  
  return EXIT_SUCCESS;
}
