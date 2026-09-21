// A (partial) implementation of selection sort,
// using lots of pointer arithmetic.

#include <stdlib.h>
#include <stdio.h>

/** Maximum length of the list to sort. */
#define LIST_LIMIT 1000

// Swap the values pointed to by a and b.
void swap( int *a, int *b )
{
  // Implement this funciton, easy
  // ...
}

// Return a pointer to the element of the given array with the smallest value.
int *findSmallest( int *list, int len )
{
  int *smallest = list;
  for ( int i = 1; i < len; i++ ) {
    // Fill in the body of this loop, without
    // declaring any more variables.  Just use
    // the smallest pointer to keep up with the
    // smallest value you've found so far.
    // ...
  }

  return smallest;
}

// Print the contents of the given list.
void printList( int *list, int len )
{
  while ( len ) {
    // Fill in the body of this loop, without
    // declaring any more variables.  Modify the parameters as you
    // iterate, to move through the list and exit the loop when you've
    // printed everything.
    // ...
  }

  printf( "\n" );
}

int main( int argc, char *argv[] )
{
  // List of integer values to sort.
  int list[ LIST_LIMIT ];

  // Number of items on the list.
  int len = 0;

  // Check for one command-line argument.
  if ( argc != 2 ) {
    fprintf( stderr, "usage: sortList INPUT_FILE.TXT\n" );
    exit( EXIT_FAILURE );
  }
  
  // Open an input file given on the command line, read a list of integers into the
  // list array.

  // Add code to open the input file and read in the list of numbers.
  // ...

  // For each index, find the smallest item from the remaining
  // (unsorted) portion of the list.
  for ( int i = 0; i < len; i++ ) {

    // Here's a clever trick.  Call findSmallest() with a pointer to
    // the start of the unsorted part of list.  It's just getting an offset
    // into our list array, but it can use as if it was a whole (shorter) array.
    int *p = findSmallest( list + i, len - i );

    // Swap the smallest item into the first position in the unsorted part of the
    // list.
    swap( list + i, p );

    // Now, the sorted part of the list is a little bit longer and the
    // unsorted part is a little shorter.
  }

  printList( list, len );

  return EXIT_SUCCESS;
}
