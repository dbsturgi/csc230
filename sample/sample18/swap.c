// Demonstration that macros can do things regular
// functions can't

#include <stdio.h>

// This should be able to swap values of any type, as long as you tell
// it the type to use. (you could make a smarter macro than this).
#define SWAP(a, b, type) \
{ \
   type temp = a; \
   a = b; \
   b = temp; \
}


int main(void)
{
   int x = 5;
   int y = 7;
   printf("x=%d y=%d\n", x, y);

   // Pass-by-name lets the macro use our variables x and y.
   SWAP(x, y, int);

   printf("x=%d y=%d\n", x, y);

   return 0;
}   
