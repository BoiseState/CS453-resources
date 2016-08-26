#include "Node.h"


struct node* createNode(void *obj)
{
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->obj = obj;
    return newNode;
}

void freeNode (struct node *node , void (*freeObject)(void *))
{
    if (node == NULL) return;
    (*freeObject)(node->obj);
    free(node);
}

