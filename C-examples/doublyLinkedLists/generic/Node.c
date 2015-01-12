
#include "Node.h"


NodePtr createNode(const void *obj)
{
	NodePtr newNode = (NodePtr) malloc (sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;


	newNode->obj = (void *) obj; /* We need to cast from
                                        (const void *) to (void *)
                                        to let the compiler know
                                        that we know what we are 
                                        doing here. We aren't 
                                        actually modifying obj, we
                                        are just assigning it to the
                                        non-const obj in the Node. */
	return newNode;
}

void freeNode (const NodePtr node, void (*freeObject)(const void *))
{
	if (node == NULL) return;
	(*freeObject)(node->obj);
	free(node);
}

