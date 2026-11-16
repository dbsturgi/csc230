// Demonstration of the union, as a field with an anonymous type.

#include <stdio.h>

int main( int argc, char *argv[] )
{
  // This definition is more typical.  We're only going
  // to use this union inside this struct, so we don't even
  // give its type a name.  We just need a name for its field.
  struct Contact {
    // Name of a person.
    char name[ 20 ];

    // This enum is just to tell me what contact holds.
    enum { email, phone, coords } type;

    // Here, we have an instance of this type, but no name
    // for the type itself.
    union {
      char email[ 24 ];
      short phone[ 3 ];
      double coords[ 2 ];
    } info;
  };

  struct Contact contacts[] = { 
    { "Mary", email, { .email = "mary@qmail.egg" } },
    { "Bill", phone, { .phone = { 919, 867, 5309 } } },
    { "Mickey", coords, { .coords = { 28.417881, -81.5788726 } } },
  };

  for ( int i = 0; i < sizeof( contacts ) / sizeof( contacts[ 0 ] ); i++ ) {
    // To access parts of the union, we first need to check how we're using it.
    if ( contacts[ i ].type == phone )
      printf( "phone: %03d-%03d-%04d\n", contacts[ i ].info.phone[ 0 ],
              contacts[ i].info.phone[ 1 ], contacts[ i ].info.phone[ 2 ] );
    else if ( contacts[ i ].type == email )
      printf( "email: %s\n", contacts[ i ].info.email );
    else
      printf( "coords: %f, %f\n", contacts[ i ].info.coords[ 0 ],
              contacts[ i ].info.coords[ 1 ] );
  }
}

