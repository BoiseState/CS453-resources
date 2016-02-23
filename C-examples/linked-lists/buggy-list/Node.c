
#include "Node.h"


NodePtr createNode(JobPtr data)
{
    NodePtr newNode = (NodePtr) malloc (sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

void freeNode (NodePtr node)
{
}

