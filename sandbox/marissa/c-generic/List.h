#ifndef __LIST_H
#define __LIST_H

#include "Node.h"

struct list {
	int size;
	struct node* head;
};

/**
 * Constructor
 */
struct list* createList();

/**
 * Destructor
 */
void freeList(struct list* list);

/**
 * Add to front.
 */
void addAtFront(struct list* list, struct node* node);

/**
 * Remove from front.
 */
struct node* removeFront(struct list* list);

/**
 * Searches for the specified object.
 */
struct node* searchList(struct list* list, void* object);

/**
 * Prints the contents of the list.
 */
void printList(struct list* list);

#endif /* __LIST_H */
