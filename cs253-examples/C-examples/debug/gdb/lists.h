
#ifndef __LISTS_H
#define __LISTS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node *  NodePtr;

typedef int ItemType;

struct node {
    ItemType item;
    NodePtr  next;
};


/* prototypes */
NodePtr ReverseList(NodePtr L);
void PrintList(NodePtr L);

#endif /* __LISTS_H */
