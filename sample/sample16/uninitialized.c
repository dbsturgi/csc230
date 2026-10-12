// This is a bad program.  It uses heap-allocated and stack-allocated
// memory that's uninitialized.  It does the same thing for statically-
// allocated memory, but that's guaranteed to be initialized, so it's
// not an error.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A statically-allocated array (initialized to zeros)
int staticArray[ 10 ];

int main()
{
  // A stack-allocated array (uninitialized)
  int stackArray[ 10 ];

  // A heap-allocated array (uninitialized)
  int *heapArray = (int *)malloc( 10 * sizeof( int ) );

  // How many values are zero. (for this example, this is really
  // just an excuse to look at each uninitialized value.
  int zcount = 0;

  // This should be OK.
  for ( int i = 0; i < 10; i++ )
    if ( staticArray[ i ] == 0 )
      zcount++;

  // This should show up as uninitialized.
  for ( int i = 0; i < 10; i++ )
    if ( stackArray[ i ] == 0 )
      zcount++;

  // Also an errror, using uninitialized memory.
  for ( int i = 0; i < 10; i++ )
    if ( heapArray[ i ] == 0 )
      zcount++;

  // Report how many zeros we saw.
  printf( "%d zeros\n", zcount );

  // Free the memory when we're done.
  free( heapArray );
  
  return 0;
}
