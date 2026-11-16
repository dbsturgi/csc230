// Demonstration of the union.

#include <stdio.h>

int main( int argc, char *argv[] )
{
  // Either an email address, a phone or, well, global coordinates.
  union ContactInfo {
    char email[ 24 ];
    short phone[ 3 ];
    double coords[ 2 ];
  };

  union ContactInfo bill;

  // bill has a phone number
  bill.phone[ 0 ] = 919;
  bill.phone[ 1 ] = 867;
  bill.phone[ 2 ] = 5309;

  union ContactInfo mary = { .email = "mary@qmail.egg" };

  // Bill remembers a phone number.
  printf( "phone: %03d-%03d-%04d\n", bill.phone[ 0 ], bill.phone[ 1 ], bill.phone[ 2 ] );

  // Mary rembers an email remembers a phone number.
  printf( "email: %s\n", mary.email );

  // But here, who knows what you'll get.
  printf( "phone: %03d-%03d-%04d\n", mary.phone[ 0 ], mary.phone[ 1 ], mary.phone[ 2 ] );

  // A struct that holds a name and either email
  // phone or global coordinates.
  struct Contact {
    // Name of a person.
    char name[ 20 ];

    // This enum is just to tell me what contact holds.
    enum { email, phone, coords } type;

    // One of three possible types of contact info.
    union ContactInfo info;
  };

  struct Contact contacts[] = { 
    { "Mary", email, { .email = "mary@qmail.egg" } },
    { "Bill", phone, { .phone = { 919, 867, 5309 } } },
    { "Mickey", coords, { .coords = { 28.417881, -81.5788726 } } },
  };

  // We can check the total memory for this array.
  printf( "Size: %zd\n", sizeof( contacts ) );

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
