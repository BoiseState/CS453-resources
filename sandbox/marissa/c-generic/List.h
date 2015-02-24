#ifndef LIST_H
#define LIST_H


#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

struct list {
	int size;
	struct node *head;
};


/**
 * Constructor
 */
struct list *createList();

/**
 * Destructor
 */
void freeList(struct list *list);

/**
 * Add to front
 */
void addAtFront(struct list *list, int element);

void printList(struct list *list);


#endif
