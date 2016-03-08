/*
    Node.h: Defines the interface for a node of a doubly-linked list.
*/

#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    void *obj;
    struct node *next;
    struct node *prev;
};

/**
 * Constructor: Allocates a new Node structure and initializes its members.
 * <code>(obj = obj; next = NULL, prev = NULL)</code>.
 *
 * @return a pointer to the allocated node.
 */
struct node* createNode (void *obj);

/**
 * Frees the object stored in the given node (using the function that freeObject
 * points to) and the <code>struct node *</code> itself.
 *
 * Does nothing if node is <code>NULL</code>.
 *
 * @param node A pointer to a <code>struct node</code>.
 * @param freeObject A pointer to a function that returns void and takes
 *          a generic pointer as an argument.
 */
void freeNode(struct node *node, void (*freeObject)(void *));

#endif /* __NODE_H */
