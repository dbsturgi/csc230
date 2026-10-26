/** An abstract data type for a set of integer values.  The client is insulated
    details of the implementation. */

#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>

/** This is an incomplete type defintion.  There's a Set defined somewhere, but
    for now you can use it in name only. */
typedef struct SetStruct Set;

/** make a new set, and return it by address. */
Set *makeSet();

/** Insert the given value into the set, or do nothing if it's already
    in the set. */
void insertValue( Set *s, int val );

/** Return true if the given value is in the set. */
bool containsValue( Set *s, int val );

/** Free the memory for the given set. */
void destroySet( Set *s );

#endif
