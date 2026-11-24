#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Print an error message and exit unsuccessfully
static void fail( char const *message )
{
  fprintf( stderr, "%s\n", message );
  exit( EXIT_FAILURE );
}

int main( int argc, char *argv[] ) {
  // Check parameters, and open input and output files.
  if ( argc != 4 )
    fail( "usage: encrypt KEY INPUT-FILENAME OUTPUT-FILENAME\n" );

  FILE *infile = fopen( argv[ 2 ], "r" );
  if ( ! infile )
    fail( "Can't open input file\n" );
  
  FILE *outfile = fopen( argv[ 3 ], "wb" );
  if ( ! outfile )
    fail( "Can't open output file\n" );

  // Make a 16-byte copy of the key given on the command line.  The
  // one on the command line might be too short, or too long.  Limit
  // it to just the first 16 bytes if it's too long, and pad with zeros
  // if it's not long enough.  This will just be a 16-byte array, not a
  // null-terminated string.
  unsigned char key[ 16 ];

  // ...

  // Make a new EVP cipher context object.
  EVP_CIPHER_CTX *ctx;
  if ( ! ( ctx = EVP_CIPHER_CTX_new()) )
    fail( "Can't create encrypt context\n" );

  // Initialize the context object to perform 128-bit AES encryption
  // in electronic codebook (ecb) mode, using the given key and no
  // initialization vector.
  if ( EVP_EncryptInit_ex( ctx, EVP_aes_128_ecb(), NULL, key, NULL ) != 1 )
    fail( "EVP_EncryptInit_ex failed" );

  // Disable automatic padding, so we can encrypt one block at a time.
  if ( EVP_CIPHER_CTX_set_padding( ctx, 0 ) != 1 )
      fail( "Failed to set padding\n" );

  // Read the input file 16 bytes at a time, encrypting each block with
  // the key.  If the last block is too short (i.e., if the file isn't
  // a multiple of 16 bytes in length), pad with zeros.
  unsigned char block[ 16 ];
  int len;
  while ( ( len = fread( block, sizeof( unsigned char ), sizeof( block ), infile ) ) ) {
    // Pad any short blocks with zeros.

    // ...
    
    // Encrypt this block.
    unsigned char output[ 16 ];

    // ...
    

    // Write this encrypted block out to the output file.

    // ...
  }

  // Free the context object.
  EVP_CIPHER_CTX_free( ctx );

  // Close the two file and exit.
  fclose( infile );
  fclose( outfile );
  return EXIT_SUCCESS;
}
