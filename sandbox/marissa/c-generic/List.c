#include "List.h"


/**
 * Constructor
 */
struct list *createList()
{
	struct list *list = (struct list *) malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;

	return list;
}

void addAtFront(struct list *list, int element)
{
	if(list == NULL) return;
	/* if(element == NULL) return; */

	struct node *nodeToAdd = createNode(element);
	//1. list is currently empty.
	if(list->head == NULL) {
		// set head to node.
		list->head = nodeToAdd;

	}

	// 2. its not.
	else {
		nodeToAdd->next = list->head;
		list->head = nodeToAdd;
	}
	list->size++;

}

void printList(struct list *list){
	if(list == NULL)
		printf("NULL);

}
