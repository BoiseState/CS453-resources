#include "Node.h"
#include <stdlib.h>
/**
 * constructor
 */
struct node* createNode(int object)
{
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->object = object;
	node->next = NULL;

	return node;
}

/**
 * Destructor
 */
void freeNode(struct node* node);
