#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Multiplier for converting degrees to radians */
#define DEG_TO_RAD ( M_PI / 180 )

/** Radius of the earth in miles. */
#define EARTH_RADIUS 3959.0

/** Print a usage message to standard error and exit unsuccessfully. */
static void usage()
{
  fprintf( stderr, "usage: gps <city-file>\n" );
  exit( EXIT_FAILURE );
}

/** General-purpose function to complain about the input format (which
    shouldn't actualy happen when we're testing your code (but it's good
    to think about how you could handle this). */
static void invalidInput()
{
  fprintf( stderr, "invalid input\n" );
  exit( EXIT_FAILURE );
}

/** Given the latitude and longitude of two locations, return the (approximate)
    distance between them, in miles. */
double globalDistance( double lat1, double lon1, double lat2, double lon2 )
{
  // OK, pretend the center of the earth is at the origin, turn these
  // two locations into vectors pointing from the origin.
  // This could be simplified.
  double v1[] = { cos( lon1 * DEG_TO_RAD ) * cos( lat1 * DEG_TO_RAD ),
                  sin( lon1 * DEG_TO_RAD ) * cos( lat1 * DEG_TO_RAD ),
                  sin( lat1 * DEG_TO_RAD ) };

  double v2[] = { cos( lon2 * DEG_TO_RAD ) * cos( lat2 * DEG_TO_RAD ),
                  sin( lon2 * DEG_TO_RAD ) * cos( lat2 * DEG_TO_RAD ),
                  sin( lat2 * DEG_TO_RAD ) };

  // Dot product these two vectors.
  double dp = 0.0;
  for ( int i = 0; i < sizeof( v1 ) / sizeof( v1[ 0 ] ); i++ )
    dp += v1[ i ] * v2[ i ];
  
  // Floating point rounding could give us a dot product a little
  // larger than 1, in this case, we'll just say the angle (and
  // distance) is zero.
  if ( dp > 1 )
    return 0;
  
  // Compute the angle between the vectors based on the dot product.
  double angle = acos( dp );

  // Return distance based on the radius of the earth.
  return EARTH_RADIUS * angle;
}

/** Struct representation for a city, with a name and a location in latitude
    and longitude. */

// ...

/** While we're processing a query, we store the current query location
    here, as a global.  That's a little ugly, but it makes it possible for
    the comparison function to see the location.  It needs this in order
    to compare cities. */
static double qLat, qLon;

/** function for comparing the distance of two cities to the query location
    at qLat, qLon. */
int compareDist( const void *aptr, const void *bptr ) {
  // I'm sorting an array of struct City instances, so convert the generic
  // pointer parameters to pointers to the two instances I'm supposed to compare.
  const struct City *a = aptr;
  const struct City *b = bptr;

  // Compute distance from the query to each of the two cities.

  // ...

  // Return -1, 0 or 1 depending on which city is closer.

  // ...
}

/** Read the name and location of a city from the given file, and store it
    in the struct pointed to by cty. */
void readCity( FILE *fp, struct City *cty ) {

  // ...

}

int main( int argc, char *argv[] )
{
  if ( argc != 2 )
    usage();

  // Open an input file given as the only command-line argument.
  FILE *fp = fopen( argv[ 1 ], "r" );
  if ( !fp ) {
    fprintf( stderr, "Can't open file: %s\n", argv[ 1 ] );
    usage();
  }

  // Read the number of cities
  int n;
  if ( fscanf( fp, "%d", &n ) != 1 || n < 1 )
    invalidInput();

  // Dynamically allocate an array of City structs that's large enough for
  // all the cities we have to read.
  
  // ...

  // Use the readCity function to fill in the fields of all the cities.

  // ...

  // Keep reading queries until we get an invalid input or reach end-of-file.
  int c;
  while ( scanf( "%lf%lf%d", &qLat, &qLon, &c ) == 3 ) {
    // Sort the cities by distance to the qurery.

    // ...

    // Print the requested number of nearby cities.

    // ...
  }

  // Free the memory for the list of cities.

  // ...

  return EXIT_SUCCESS;
}
