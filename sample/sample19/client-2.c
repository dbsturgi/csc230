// Client program for the set implementation.
// Link this one with set-1

#include "set-2.h"
#include <stdio.h>

int main()
{
  // Make a set.
  Set *s = makeSet();

  // Put some values into it.
  insertValue( s, 2 );
  insertValue( s, 3 );
  insertValue( s, 5 );
  insertValue( s, 7 );
  insertValue( s, 11 );
  
  // Print a report of values that are in the set, or not.
  for ( int i = 0; i <= 12; i++ )
    if ( containsValue( s, i ) )
      printf( "%d is in the set\n", i );
    else
      printf( "%d is not in the set\n", i );

  // Free the set before we exit.
  destroySet( s );
}
