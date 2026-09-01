//
// Demonstration of break, continue and goto (the statement that must not be named)
// These let us change the flow of control in ways that aren't reflected in the structure
// of the program (so, they generally hurt readability).  Break and continue are not
// as bad as goto, since they at least act on just the innermost loop.
//
#include <stdio.h>
#include <stdbool.h>

int main( void )
{
  // A nested loop, with no fancy changes in the flow of control.
  int val = 0;
  for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ ) {
      printf( "%2d ", val );
      val += 1;
    }
    printf( "\n" );
  }
  
  printf( "\n-------------------------\n\n" );

  // A nested loop, with continue to sometimes skip part of a loop
  // iteration.
  
  val = 0;
  for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ ) {
      printf( "%2d ", val );
      if ( j > i )
        continue;
      val += 1;
    }
    printf( "\n" );
  }

  printf( "\n-------------------------\n\n" );

  // A nested loop, with break to exit the innermost loop early.
  val = 0;
  for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ ) {
      printf( "%2d ", val );
      if ( j > i )
        break;
      val += 1;
    }
    printf( "\n" );
  }

  printf( "\n-------------------------\n\n" );

  // A nested loop, with goto to do the job of break.
  val = 0;
  for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ ) {
      printf( "%2d ", val );
      if ( val >= 55 )
        goto done;
      val += 1;
    }
    printf( "\n" );
  }
 done:

  printf( "\n-------------------------\n\n" );

  // No structured loops at all.  We can do it all with goto.
  // I don't like to write this code; I sure wouldn't like to read it.
  val = 0;
  int i = 0;
 outer_top:
  if ( i >= 10 )
    goto finished;
  int j = 0;
 inner_top:
  if ( j >= 10 )
    goto done_2;
  printf( "%2d ", val );
  val += 1;
  j++;
  goto inner_top;
 done_2:
  printf( "\n" );
  i++;
  goto outer_top;
 finished:

  // The following code is bad, so I've used the preorocessor to
  // omit it.

#ifdef NEVER
  // You can even jump inside a loop, but it's probably a bad idea.
  
  val = 0;
  goto inside;
  for ( int i = 0; i < 10; i++ ) {
    for ( int j = 0; j < 10; j++ ) {
    inside:
      // After jumping to this label, there's no way to know what i
      // and j will be.
      printf( "%2d ", val );
      val += 1;
    }
    printf( "\n" );
  }
#endif

  return 0;
}
