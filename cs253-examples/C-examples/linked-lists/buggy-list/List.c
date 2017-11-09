#include <stdio.h>
#include <stdlib.h>
#include "List.h"


static struct node* reverse(struct node* L);
static void print(struct node* node);



struct list* createList()
{
	struct list* list = (struct list*) malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

int getSize(struct list* L)
{
	return L->size;
}

Boolean isEmpty(struct list* L)
{
	if (L->size == 0)
		return TRUE;
	else
		return FALSE;
}

void addAtFront(struct list* list, struct node* node)
{
	if (list == NULL) return;
	if (node == NULL) return;
	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}

void addAtRear(struct list* list, struct node* node)
{
}

struct node* removeFront(struct list* list)
{
	return NULL;
}

struct node* removeRear(struct list* list)
{
	return NULL;
}

struct node* removeNode(struct list* list, struct node* node)
{
	return NULL;
}

struct node* search(struct list* list, int key)
{
	return NULL;
}

void reverseList(struct list* L)
{
	L->tail = L->head;
	L->head  = reverse (L->head);
}

static struct node* reverse(struct node* L)
{
	return NULL;
}

void printList(struct list* L)
{
	if (L) print(L->head);
}

static void print(struct node* node)
{
	int count = 0;
	char *buf;

	while (node) {
		buf = toString(node->data);
		printf(" %s -->", buf);
		node = node->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
	printf(" NULL \n");
}


void freeList(struct list* L)
{
}
