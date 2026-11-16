// How to use the enum hack.  An uglyclever way to get a named,
// compile-time constant that respects scope.

#include <stdio.h>

// This is the enum hack.  A way of just using enum for constant
// values (as long as you just need int)
enum { SIZE = 100 };

// But, see, these are compile-time constant.
int list[ SIZE ];

void f();

int main( int argc, char *argv[] )
{
  printf( "list is %zd elements\n", sizeof( list ) / sizeof( int ) );
  f();
}

// Just to have another scope.
void f()
{
  // And, this trick respects scope.  This one shadows
  // the SIZE identifier with global scope.
  enum { SIZE = 25 };

  int list2[ SIZE ];
  printf( "list2 is %zd elements\n", sizeof( list2 ) / sizeof( int ) );
}
