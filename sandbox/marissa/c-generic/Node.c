#include "Node.h"
#include <stdlib.h>

/**
 * constructor
 */
struct node* createNode(void *object)
{
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->object = object;
	node->next = NULL;

	return node;
}

/**
 * Destructor
 */
void freeNode(struct node* node)
{
	if(node == NULL) return;
	if(node->object != NULL)
		freeObject(node->object);
	free(node);

	node = NULL;
}

/**
 * TODO: implement me.
 */
void printNode(struct node* node)
{
	if(node == NULL) return;
	if(node->object == NULL) return;

	char *objstr = toString(node->object);
	printf("%s", objstr);
}
