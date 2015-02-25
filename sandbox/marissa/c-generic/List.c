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

/**
 * TODO: implement me.
 */
void freeList(struct list* list)
{
	if(list == NULL) return;

	struct node *node = list->head;
	while(node) // free all the ndoes
	{
		struct node *temp = node->next;
		freeNode(node);
		node = temp;
	}

	free(list);
	list = NULL;
}

/**
 * Add to the front of the list.
 */
void addAtFront(struct list *list, struct node* node)
{
	if(list == NULL) return;
	if(node == NULL) return;

	// wrap element in node so we can add it.
	/* struct node *nodeToAdd = createNode(element); */

	if(list->head == NULL) {           // case 1. list is currently empty.
		list->head = node;
	} else {                           // case 2. it's not empty.
		node->next = list->head;
		list->head = node;
	}
	list->size++;
}

/**
 * TODO: implement me.
 */
struct node* removeFront(struct list* list)
{
	return NULL;
}

/**
 * TODO: implement me.
 */
struct node* searchList(struct list* list, void *object)
{
	if(list == NULL) return NULL;

	struct node *node = list->head;
	while(node != NULL)
	{
		// check for equality.
		if(equals(node->object,object)) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

/**
 * TODO: implement me.
 */
void printList(struct list *list)
{
	if(list != NULL)
	{
		struct node *node = list->head;
		while(node != NULL)
		{
			//print node.
			printNode(node);
			printf("-->");
			node = node->next;
		}
	}
	printf("NULL\n");
}
