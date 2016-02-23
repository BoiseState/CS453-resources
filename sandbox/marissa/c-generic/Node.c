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
void freeNode(struct node* node, void (*freeObject)(const void *))
{
    if(node == NULL) return;
    if(node->object != NULL)
        (*freeObject)(node->object); // make sure to dereference the function
    free(node);

    node = NULL;
}

/**
 * Prints the node using the toString() method in Object.h
 * This needs to be fixed. We want to store the reference
 * the toString method in the list structure.
 */
void printNode(struct node* node, char *(toString)(const void *))
{
    if(node == NULL) return;
    if(node->object == NULL) return;

    char *objstr = (*toString)(node->object); // make sure to dereference the function
    printf("%s", objstr);

    // There is a memory leak here!! We need to free the objstr
    // after we print it.
    //free(objstr);
}
