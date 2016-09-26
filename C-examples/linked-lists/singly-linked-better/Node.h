/*
    Node.h: Defines the interface for a node of a singly-linked list.
*/

#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

/**
 * Constructor: Allocates a new Node structure and initializes its members.
 * <code>(obj = obj; next = NULL)</code>.
 *
 * @return a pointer to the allocated node.
 */
struct node *createNode(int value);

/**
 * Frees the <code>struct node *</code> itself.
 *
 * Does nothing if node is <code>NULL</code>.
 *
 * @param node A pointer to a <code>struct node</code>.
 */
void freeNode(struct node *node);

#endif /* __NODE_H */
