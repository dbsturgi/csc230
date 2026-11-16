/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

/** Definition of a struct. */
struct Record {
  char a;  // I'm at offset 0 from the start.
  int b;   // I'm at offset 4 from the start.
  short c; // I'm at offset 8 from the start.
};

// Our assembly language function expects a pointer to an isntance
// of this struct.
void initStruct( struct Record *p );

int main()
{
  // Make an instance of this struct.
  struct Record myStruct;
  
  // Let our assembly language function initialize this struct.
  initStruct( &myStruct );

  // Report its fields.
  printf( "myStruct.a = %c\n", myStruct.a );
  printf( "myStruct.b = %d\n", myStruct.b );
  printf( "myStruct.c = %d\n", myStruct.c );
  
  return EXIT_SUCCESS;
}
