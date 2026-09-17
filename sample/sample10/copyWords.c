// Copying all the words in a text file.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Try to open a source file, and complain if we can't
  FILE *input = fopen( "input.txt", "r" );
  if ( ! input ) {
    fprintf( stderr, "Can't open input.txt\n" );
    exit( EXIT_FAILURE );
  }
                  
  // Try to open an output file, and complain if we can't
  FILE *output = fopen( "output.txt", "w" );
  if ( ! output ) {
    fprintf( stderr, "Can't create output.txt\n" );
    exit( EXIT_FAILURE );
  }

  // Read words of up to 10 characters each.
  char word[ 11 ];
  while ( fscanf( input, "%10s", word ) == 1 )
    // Print the word on a line
    fprintf( output, "%s\n", word );

  // Close both our files.
  fclose( input );
  fclose( output );

  return EXIT_SUCCESS;
}
