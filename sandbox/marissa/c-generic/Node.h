#ifndef __NODE_H
#define __NODE_H

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
void freeNode(struct node* node, void (*freeObject)(const void *));

/**
 * Prints the node.
 */
void printNode(struct node* node, char *(toString)(const void *));

#endif /* __NODE_H */
