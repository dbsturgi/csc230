/** Driver program in C.  See the corresponding assembly source
    for build instructions. */

#include <stdlib.h>
#include <stdio.h>

// Function that uses a couple of local variables.
void localVars( void );

int main()
{
  // Call the function.  Everything happens inside here.
  localVars();
  
  return EXIT_SUCCESS;
}
