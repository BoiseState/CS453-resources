#ifndef __NODE_H
#define __NODE_H

#include "Object.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
	void *object;
	struct node* next;
};

/**
 * constructor
 */
struct node* createNode(void *object);

/**
 * Destructor
 */
void freeNode(struct node* node);

/**
 * Prints the node.
 */
void printNode(struct node* node);

#endif /* __NODE_H */
