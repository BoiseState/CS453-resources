
/*
    List.h: Defines the interface for a doubly-linked list.
*/

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "Node.h"

typedef struct list List;
typedef struct list * ListPtr;

struct list {
    int size;
    NodePtr head;
    NodePtr tail;
};

/* prototypes of public methods */

ListPtr createList(); /* constructor */
void freeList(ListPtr L); /* destructor */

int getSize(ListPtr L);

Boolean isEmpty(ListPtr L);

void addAtFront(ListPtr list, NodePtr node);
void addAtRear(ListPtr list, NodePtr node);

NodePtr removeFront(ListPtr list);
NodePtr removeRear(ListPtr list);
NodePtr removeNode(ListPtr list, NodePtr node);

NodePtr search(ListPtr list, int key);

void reverseList(ListPtr  L);

void printList(ListPtr L);


#endif /* __LIST_H */
