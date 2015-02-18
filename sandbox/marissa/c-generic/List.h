#include "Node.h"

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
