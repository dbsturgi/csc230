#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

// Print an error message and exit unsuccessfully
static void fail( char const *message )
{
  fprintf( stderr, "%s\n", message );
  exit( EXIT_FAILURE );
}

int main()
{
  EVP_CIPHER_CTX *ctx;
  if ( ! ( ctx = EVP_CIPHER_CTX_new()) )
    fail( "Can't create encrypt context\n" );

  // A key for encrypting, 16 bytes long.
  unsigned char *key = (unsigned char *) "abcdefgh12345678";

  // Initialize the context object for AES 128-bit encryption.
  if ( EVP_EncryptInit_ex( ctx, EVP_aes_128_ecb(), NULL, key, NULL ) != 1 )
    fail( "EVP_EncryptInit_ex failed" );

  // Disable automatic padding, so we can encrypt and decrypt one block at a time.
  if ( EVP_CIPHER_CTX_set_padding( ctx, 0 ) != 1 )
      fail( "Failed to set padding\n" );

  // A message to encrypt, 16 characters in length.
  unsigned char message[ 16 ];
  memcpy( message, "Here's a message", sizeof( message ) );

  // Encrypt the message 16-byte message to 16 bytes of ciphertext.
  unsigned char cipher[ 16 ];
  int outLen;
  if ( EVP_EncryptUpdate( ctx, cipher, &outLen, message, sizeof( message ) ) != 1 )
      fail( "Failure to encrypt block\n" );

  // Print the encrypted message, in Hex, since it probably looks
  // like random garbage.
  printf( "Encrypted Message:" );
  for ( int i = 0; i < sizeof( cipher ); i++ )
    printf( " %02X", cipher[ i ] );
  printf( "\n" );

  // Re-initialize the context object for AES 128-bit decryption (hope this is OK)
  if ( EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL) != 1 )
    fail( "EVP_DecryptInit_ex failed" );

  // Decrypt the 16 bytes of ciphertext.
  unsigned char plain[ 16 ];
  if ( EVP_DecryptUpdate( ctx, plain, &outLen, cipher, sizeof( cipher ) ) != 1 )
      fail( "Failure to decrypt block\n" );
  
  // We should get our original message back, but we didn't include a null
  // terminator at the end.
  printf( "Decrypted Message: " );
  for ( int i = 0; i < sizeof( plain ); i++ )
    putchar( plain[ i ] );
  printf( "\n" );

  // Free the context object.
  EVP_CIPHER_CTX_free( ctx );
  
  return 0;
}
