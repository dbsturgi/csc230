/**
   A character I/O program that echos the input, replacing spaces with
   dashes and capitalizing all the letters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  // Keep reading until we hit the EOF.
  int ch = getchar();
  while ( ch != EOF ) {
    // Print a - if the input character was a space.  Otherwise, just
    // echo the input character unchanged.
    if ( ch == ' ' )
      putchar( '-' );
    else
      putchar( toupper( ch ) );
    ch = getchar();
  }

  // Exit successfully (this constant is more meaningful than just a zero)
  return EXIT_SUCCESS;
}
