
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*

	list.c 
		Contains functions to manipulate a doubly-linked list.
 
*/


/* private methods */
static void print(const NodePtr node, char * (*toString)(const void *));

ListPtr createList(Boolean (*equals)(const void *,const void *), 
                   char * (*toString)(const void *),
		   void (*freeObject)(const void *))
{
	ListPtr list;
	list = (ListPtr) malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->equals = equals;
	list->toString = toString;
	list->freeObject = freeObject;
	return list;
}

void freeList(const ListPtr list)
{
}

int getSize(const ListPtr list)
{
	return list->size;
}

Boolean isEmpty(const ListPtr list)
{
	if (list->size == 0)
		return TRUE;
	else
		return FALSE;
}

void addAtFront(ListPtr list, NodePtr node)
{
	if (list == NULL) return;
	if (node == NULL) return;
	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}

void addAtRear(ListPtr list, NodePtr node)
{
}

NodePtr removeFront(ListPtr list)
{
	return NULL;
}

NodePtr removeRear(ListPtr list)
{
	return NULL;
}

NodePtr removeNode(ListPtr list, NodePtr node)
{
	return NULL;
}

NodePtr search(const ListPtr list, const void *obj)
{
	return NULL;
}

void reverseList(ListPtr list)
{
}

void printList(const ListPtr list)
{
	if (list) print(list->head, list->toString);
}

static void print(const NodePtr node, char * (*toString)(const void *))
{
	int count = 0;
	char *output;
    
    NodePtr temp = node;
	while (temp) {
		output = (*toString)(temp->obj);
		printf(" %s -->",output);
		free(output);
		temp = temp->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
    printf(" NULL \n");
}
 

		

