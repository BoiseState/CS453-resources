
#include "Node.h"


struct node* createNode(struct job* data)
{
    struct node* newNode = (struct node*) malloc (sizeof(struct node*));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

void freeNode (struct node* node)
{
	//Ha!!! This is a no free zone :)
}
