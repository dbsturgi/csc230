/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

// Compute the score for a given letter, using scrabble
// rules.
int letterScore( char let );

int main()
{
  printf( "%c : %d points\n", 'a', letterScore( 'a' ) );
  printf( "%c : %d points\n", 'b', letterScore( 'b' ) );
  printf( "%c : %d points\n", 'c', letterScore( 'c' ) );
  printf( "%c : %d points\n", 'd', letterScore( 'd' ) );
  printf( "%c : %d points\n", 'z', letterScore( 'z' ) );
  
  return EXIT_SUCCESS;
}
