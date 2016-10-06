#include "Node.h"

struct node* createNode(int value)
{
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->value = value;
    return newNode;
}

void freeNode (struct node *node)
{
    if (node == NULL) return;
    free(node);
}

