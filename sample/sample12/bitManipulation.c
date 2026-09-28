/*
 * Clearing, setting, testing individual bits.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main()
{
  unsigned char x, y;
  
  // Clearing selected bits

  x = 0xD3;     // binary 11010011
  
  // Clear just the low-order nibble.
  x = x & 0xF0;
  printf( "%x\n", x );
  
  x = 0xD3;     // binary 11010011
  
  // Clear just ever other bit
  x &= 0x55;
  printf( "%x\n", x );

  // Setting selected bits

  x = 0xD3;     // binary 11010011
  
  // Set just the low-order 4 bits.
  x = x | 0x0F;
  printf( "%x\n", x );

  x = 0xD3;     // binary 11010011
  
  // Set just the high and low bits
  x = x | 0x81;
  printf( "%x\n", x );

  // Flipping selected bits.

  x = 0xD3;     // binary 11010011
  
  // Filp just the low-order bit
  x ^= 0x01;
  printf( "%x\n", x );

  // Testing selected bits.

  x = 0xD3;     // binary 11010011
  
  // I wonder if the low-order nibble has
  // any bits set. (don't really need the != 0 part
  // here.
  unsigned char mask = 0x0F;
  if ( ( x & mask ) != 0 ) {
    printf( "A bit in the low-order nibble is set\n" );
  }

  // I wonder if all the bits in the low-order nibble are
  // set.
  if ( ( x & mask ) == mask ) {
    printf( "All bits in the low-order nibble is set\n" );
  }

  // Let's count the 1 bits in this random integer.
  unsigned int bill = 2348291;
  int bcount = 0;
  for ( int i = 0; i < 8 * sizeof( int ); i++ ) {
    if ( bill & 1 << i )
      bcount++;
  }
  printf( "That's %d one bits\n", bcount );
}
