// A first example of macros that take parameters.

#include <stdio.h>

// Here's how you define a macro with parameters.
// Print out twice the int value a.
#define P2(a) printf("%d\n", (a)+(a))

int main(void) {

   int x = 10;

   // Here's how you use a macro with parameters.  It looks like
   // a regular functionc all, but the name matches a macro name.
   P2(x);

   return 0;

}
