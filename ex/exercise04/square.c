// Count the nuber of points inside a 20 x 20 square centered on the origin.

#include <stdio.h>
#include <stdlib.h>

// Return the absolute value of val.
double absolute( double val )
{
  // ...
}

// Return 1 if the given x, y point is inside the 20 x 20 square.
int inside( double x, double y )
{
  // ...
}

// Read 2D points from the input and return how many are
// inside the 20 x 20 square.
int countPoints()
{
  // ...
}

int main()
{
  // Count all the points and print the result.
  printf( "%d\n", countPoints() );
  
  return EXIT_SUCCESS;
}
