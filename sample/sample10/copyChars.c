// Copying a file character-by-character

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
                  
  // Try to open an output file.
  FILE *output = fopen( "output.txt", "w" );
  if ( ! output )
    // Sneaky way to print an error and exit with one statement.
    fprintf( stderr, "Can't create output.txt\n" ), exit( EXIT_FAILURE );

  // Count number of characters copied.
  int ccount = 0;

  // Keep reading characters from the input file until
  // We reach the end-of-file.
  int ch = fgetc( input );
  while ( ch != EOF ) {
    // Count each character and write it to the output.
    ccount += 1;
    fputc( ch, output );
    
    // Read the next character.
    ch = fgetc( input );
  }

  // Close both our files.
  fclose( input );
  fclose( output );

  // Report how many characters we saw.
  printf( "Copied: %d\n", ccount );

  return EXIT_SUCCESS;
}
