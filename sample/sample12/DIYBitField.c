/** Demonstration of how to divide up a value into bit fields ourselves.  We use
    bitwise operators to access and manipulate just particular sections of the
    bits.  This can let us use any section of the bits as if it was a little
    integer value. */

#include <stdio.h>
#include <stdlib.h>

// Increment just bits 8 - 11, returning the resut, with the
// remaining bits left unchanged.
unsigned short increment8to11( unsigned short s )
{
  // Extract the contents of the bit field, and move it into the low-order bits.
  unsigned short bitField = ( s & 0x0F00 ) >> 8;

  // Add one our copy of the bit field's value
  bitField++;

  // Get ready to put the updated value of the bit field back.  Clear out the contents
  // of the bit field.
  s &= 0xF0FF;

  // Shift the updated bit field back to where it goes, mask of any remaining bits (in
  // case there was some overflow) and or the result back into the original value.
  s |=  ( ( bitField << 8 ) & 0x0F00 );

  // We're done, reutrn the result.
  return s;
}

int main() {
  // Make up a value containing some random-looking bits.
  unsigned short s = 0xA2B3;

  // Show how this works by incrementing just this bit field a bunch of times.
  for ( int i = 0; i < 16; i++ ) {
    s = increment8to11( s );
    printf( "%04X\n", s );
  }

  return EXIT_SUCCESS;
}
