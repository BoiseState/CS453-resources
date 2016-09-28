#include "Node.h"

struct node *createNode(int value)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->value = value;
    n->next = NULL;
    return n;
}

void freeNode(struct node *node)
{
    if (node != NULL) {
    	free(node);
	}
}
