#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Number of arguments required by the program. */
#define REQUIRED_ARGS 2

/** Maximum number of lines we support in a text file. */
#define MAX_LINES 1024

/**
   Print out a usage message, then exit unsuccessfully.
 */
static void usage() {
  fprintf( stderr, "usage: frame TEXT_FILE\n" );
  exit( EXIT_FAILURE );
}

/**
   Read a line of text from the given file and return it.
   @param fp File to read text from.
   @return Dynamically allocated string with the text of the next line
   from fp, or NULL if we're already at the EOF.
 */
char *readLine( FILE *fp )
{
  // ...
}

/**
   Read text from the given file, storing a pointer to each
   line in the text array and returning the total number of lines
   read.
   @param fp File to read text from.
   @param text Filled in with pointers to memory for each line.
   @return Number of text lines read.
*/
int readText( FILE *fp, char *text[ MAX_LINES ] )
{
  // ...
}

void printLine( int len )
{
  putchar( '+' );
  for ( int i = 0; i < len; i++ )
    putchar( '-' );
  printf( "+\n" );
}

/**
   Starting point for prgram execution.
   @param argc Number of commad-line arguments.
   @param argv Array of poiters to each command-line argument.
   @return Program exit status.
 */
int main( int argc, char *argv[] )
{
  // Complain if we don't have the expected number of arguments.
  if ( argc != REQUIRED_ARGS )
    usage();

  // Open the given input file.

  // Read each line of text into dynamically allocated memory.
  char *text[ MAX_LINES ];
  int lines;
  // ...


  // Close the input file.
  // ...

  // Print the text with a box around it.
  // ...

  // Free all the heap memory for the text.
  // ...

  return EXIT_SUCCESS;
}
