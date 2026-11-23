#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main()
{
  // A key for encrypting, exactly 8 characters long.
  unsigned char key[ 8 ] = "abcd1234";

  // Fill in the parity bits in the key.
  DES_set_odd_parity( &key );

  // Turn the key into a key schedule object needed to actually encrypt.
  DES_key_schedule schedule;
  DES_set_key_checked( &key, &schedule );

  // A message to encrypt, exactly 8 characters in length.
  unsigned char message[ 8 ] = "doorbell";

  // Encrypt the message 8-bytes message to 8 bytes of ciphertext.
  unsigned char cipher[ 8 ];
  DES_ecb_encrypt( &message, &cipher, &schedule, DES_ENCRYPT);
  
  // Print the encrypted message, in Hex, since it probably looks
  // like random garbage.
  printf( "Encrypted Message:" );
  for ( int i = 0; i < sizeof( cipher ); i++ )
    printf( " %02X", cipher[ i ] );
  printf( "\n" );

  // Decrypt the 8 bytes of ciphertext using the same key.
  unsigned char plain[ 8 ];
  DES_ecb_encrypt( &cipher, &plain, &schedule, DES_DECRYPT);

  // We should get our original message back, but the null wasn't part of
  // the message:
  printf( "Decrypted Message: " );
  for ( int i = 0; i < sizeof( plain ); i++ )
    putchar( plain[ i ] );
  printf( "\n" );

  return 0;
}
