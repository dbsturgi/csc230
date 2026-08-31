#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LIMIT 80

/** Report that the input is invalid and exit unsuccessfully. */
static void invalid()
{
  printf( "Invalid input\n" );
  exit( EXIT_FAILURE );
}

int main()
{
  // This is the representation of the string we're creating.  It starts out
  // as an empty string.
  char str[ STRING_LIMIT + 1 ] = "";

  // Current length of the string.  We could use strlen(), but it's
  // convenient to also have a variable for this.
  int len = 0;

  // Read the word at the start of each command.
  // ...
  while ( /* ... */ ) {
    // Read the operands for the operation.  Make sure it's valid and
    // modify the string if it is.
   
    // ... 
    
    // Print out the current state of the string.
    printf( "%s\n", str );
  }

  return EXIT_SUCCESS;
}
