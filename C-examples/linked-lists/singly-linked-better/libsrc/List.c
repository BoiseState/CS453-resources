#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct list *createList()
{
	struct list *list = (struct list *) malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	return list;
}

void freeList(struct list *list)
{
}

int getSize(const struct list *list)
{
	return 0;
}

int isEmpty(const struct list *list)
{
	return list->size == 0;
}

void addAtFront(struct list *list, struct node *node)
{
	if (list == NULL || node == NULL) {
		return; /* don't need to do anything */
	}

	if (list->head == NULL) {
		list->head = node;
	} else {
		node->next = list->head;
		list->head = node;
	}

	list->size++;
}

struct node *removeFront(struct list *list)
{
	return NULL;
}

struct node *removeNode(struct list *list, struct node *node)
{
	return NULL;
}

struct node *search(const struct list *list, const int value)
{
	return NULL;
}

void printList(const struct list *list)
{
	if (list != NULL) {
		struct node *temp = list->head;
		while (temp) {
			printf("[%d]", temp->value);
			temp = temp->next;
		}
		printf("\n");
	}
}
