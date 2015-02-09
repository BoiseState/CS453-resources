#ifndef __NODE_H
#define __NODE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	void *obj;
	struct node *next;
	struct node *prev;
};

struct node* createNode (void *obj);
void freeNode(struct node *node, void (*freeObject)(void *));

#endif /* __NODE_H */
