/*
    Object.h: Defines the interface for an object to be stored in a node
	of our doubly-linked list.
*/
#ifndef __OBJECT_H
#define __OBJECT_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} boolean;

#define MAX_KEY_DIGITS 10 /* max digits in an int */

struct object {
    int key;
    char *data;
};
/**
 * Constructor: Allocates a new object structure and initializes its members.
 *
 * @return a pointer to the allocated object.
 */
struct object* createObject (const int key, const char *data);

/**
 * Returns a string representation of the given object.
 *
 * @param obj The object to create the string for.
 * @return The string representation of this object. The user of this
 *			function is responsible for freeing the returned string.
 */
char *toString(const void *obj);

/**
 * Frees the data stored in the given object and the object itself.
 *
 * Does nothing if obj is <code>NULL</code>.
 *
 * @param obj A pointer to the <code>struct object</code> to free.
 */
void freeObject(void *obj);

/**
 * Checks if the given objects are equal. Objects are considered
 * equal if they have the same key.
 *
 * @param o1 A pointer to the first <code>struct object</code>.
 * @param o2 A pointer to the first <code>struct object</code>.
 * @return Returns 1 (true) if the objects are equal, 0 (false)) otherwise.
 */
int equals(const void *o1,const void *o2);


#endif /* __OBJECT_H */
