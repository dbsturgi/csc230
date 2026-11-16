// Demonstration of enumerated types.

#include <stdio.h>

// A new type with just 4 values.
enum ColorTag { red, green, blue, orange };

// As with struct, we can omit the tag and use typedef
// to give us a shorter name.
typedef enum { up, down, left, right } Direction;

#ifdef NEVER
// We can't do this, blue is already taken
enum MoodTag { happy, afraid, bored, blue };
#endif

void f();

int main( int argc, char *argv[] )
{
  // To make Colors, we need to use the enum keyword.
  enum ColorTag myColor = orange;
  enum ColorTag yourColor = red;

  // You can compare enum values (of the same type).
  if ( myColor == yourColor ) {
    printf( "We have the same color!\n" );
  }

  // See, we used typedef to give us a shorter name for this type.
  Direction myDirection = right;

  // Internally, enumerations are represented as integers, see:
  printf( "myDirection: %d\n", myDirection );

  // You can even compare enumeration of different types (but,
  // do you really want to?)
  if ( myColor == myDirection ) {
    printf( "Should these be equal?  Looks like they are\n" );
  }

  // You can do math on enumerated values
  myColor--;
  // Now it's blue, but be careful
  ++myColor;
  ++myColor;
  // Now its no longer a legal value of the enumerated type.

  // f() is just here to give us a different scope
  f();

  return 0;
}

void f()
{
  // Here we can define an enumerated type with a duplicated value.  It
  // will shadow the one defined at file scope.
  // We can also pick numeric values for the values.
  enum MoodTag { happy = 2, afraid, bored = 0, blue, glad  };

  enum MoodTag myMood = happy;
  
  // Look, happy and glad are the same thing.
  if ( myMood == glad ) {
    printf( "I guess I'm glad too\n" );
  }

  // We can still use Color (compiler will complain that we never
  // use this variable)
  enum ColorTag someColor = green;

  // But, this will get you a warning (good)
  someColor = blue;
}
