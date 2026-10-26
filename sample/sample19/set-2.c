#include "set-2.h"
#include <stdlib.h>

/** Node used to represent a value in a set. */
struct Node {
  /** Value in the set. */
  int val;

  /** Pointer to the next node. */
  struct Node *next;
};

/** Representation for a set of values (there's a typedef in the header) */
struct SetStruct {
  /** Representation for each value in the set, as a linked list. */
  struct Node *head;
};

Set *makeSet()
{
  // Allocate a set representation, and make it empty.
  Set *s = (Set *) malloc( sizeof( Set ) ) ;
  s->head = NULL;
  return s;
}

void insertValue( Set *s, int val )
{
  // See if the value's there already.
  for ( struct Node *n = s->head; n; n = n->next )
    if ( n->val == val )
      return;

  // It's not.  Add this value to the front.
  struct Node *n = (struct Node *) malloc( sizeof( struct Node ) );
  *n = (struct Node) { val, s->head };
  s->head = n;
}

bool containsValue( Set *s, int val )
{
  // Look for the given value in the list.
  for ( struct Node *n = s->head; n; n = n->next )
    if ( n->val == val )
      return true;

  // Return false if we don't find it.
  return false;
}

void destroySet( Set *s )
{
  // Free all the nodes in the set.
  while ( s->head ) {
    struct Node *n = s->head;
    s->head = s->head->next;
    free( n );
  }
  
  // Free the set itself.
  free( s );
}
