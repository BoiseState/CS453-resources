
/*
    List.h: Defines the interface for a doubly-linked list.
*/

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <common.h>
#include <Node.h>

struct list {
    int size;
    struct node * head;
    struct node * tail;
};

/* prototypes of public methods */

struct list * createList(); /* constructor */
void freeList(struct list * L); /* destructor */

int getSize(struct list * L);

Boolean isEmpty(struct list * L);

void addAtFront(struct list * list, struct node * node);
void addAtRear(struct list * list, struct node * node);

struct node * removeFront(struct list * list);
struct node * removeRear(struct list * list);
struct node * removeNode(struct list * list, struct node * node);

struct node * search(struct list * list, int key);

void reverseList(struct list *  L);

void printList(struct list * L);

Boolean checkpointList(struct list * list, char *saveFile);
struct list * restoreList(char *saveFile);

#endif /* __LIST_H */
