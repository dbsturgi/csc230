// Copying a file byte-byte-byte in binary mode.  This will behave just like
// copyChars.c on a Unix machine or MacOS, but you will see a difference on
// a windows system.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Try to open a source file in binary mode.
  FILE *input = fopen( "input.bin", "rb" );
  if ( ! input ) {
    fprintf( stderr, "Can't open input.bin\n" );
    exit( EXIT_FAILURE );
  }
                  
  // Try to open an output file in binary mode.
  FILE *output = fopen( "output.bin", "wb" );
  if ( ! output ) {
    // Sneaky way to print an error and exit with one statement.
    fprintf( stderr, "Can't create output.bin\n" );
    exit( EXIT_FAILURE );
  }

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
