#include "Node.h"

NodePtr createNode(const JobPtr data)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    return newNode;
}

void freeNode(const NodePtr node)
{
    if (node == NULL)
	return;
    freeJob(node->data);
    free(node);
}
