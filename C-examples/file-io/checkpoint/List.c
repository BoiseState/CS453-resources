
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*

	list.c 
		Contains functions to manipulate a doubly-linked list.
 
*/


/* private methods */

static NodePtr reverse(NodePtr L);
static void print(NodePtr node);



ListPtr createList()
{
	ListPtr list = (ListPtr) malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

int getSize(ListPtr L)
{
	return L->size;
}

Boolean isEmpty(ListPtr L)
{
	if (L->size == 0)
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

NodePtr search(ListPtr list, int key)
{
	return NULL;
}

void reverseList(ListPtr L)
{
}

static NodePtr reverse(NodePtr L)
{
	return NULL;
}

void printList(ListPtr L)
{
	if (L) print(L->head);
}

static void print(NodePtr node)
{
	char *output;

	while (node) {
		output = toString(node->data);
		printf("%s\n",output);
		free(output);
		node = node->next;
	}
    printf("NULL\n");
}
 

void freeList(ListPtr L)
{
}
		

/**
	Checkpoint the whole list to disk so we can restore it later.
	@param list     a pointer to a list that needs to be checkpointed
	@paramsaveFile  pathename of the checkpoint file

	@return TRUE if checkpointing succeeds, FALSE otherwise
*/

#define MAX_MSG_LENGTH 1024

Boolean checkpointList(ListPtr list, char *saveFile)
{
	NodePtr node;
	FILE *fout;
	char errmsg[MAX_MSG_LENGTH];

	if (list == NULL) return TRUE;
	if (isEmpty(list)) return TRUE;
	if (saveFile == NULL) return FALSE;
	if (strlen(saveFile) == 0) return FALSE;

	fout = fopen(saveFile, "w");
	if (!fout) {
		sprintf(errmsg, "checkpointList: %s",saveFile);
		perror(errmsg);
		return FALSE;
	}

	fwrite(&(list->size), sizeof(int), 1, fout);

	node = list->tail;
	while (node) {
		checkpointNode(node, fout);
		node = node->prev;
	}
	fclose(fout);
	return TRUE;
}



/**
	Restore the whole list from disk. This will only work if the
    list was saved with the checkpointList function. If you modify
	the checkpointList function, then this function would need to be
	modified as well.
	@param saveFile  pathename of the checkpoint file
	@param list      a pointer to the restored list
*/

ListPtr restoreList(char *saveFile)
{
	int size;
	FILE *fin;
	ListPtr list;
	NodePtr node;
	char errmsg[MAX_MSG_LENGTH];

	if (saveFile == NULL) return NULL;
	if (strlen(saveFile) == 0) return NULL;
	fin = fopen(saveFile, "r");
	if (!fin) {
		sprintf(errmsg, "restoreList: %s",saveFile);
		perror(errmsg);
		return NULL;
	}

	fread(&size, sizeof(int), 1, fin);
	if (size <= 0) return NULL;
	printf("restore: list size = %d\n", size);
	list = createList();

	while (size > 0) {
		node = restoreNode(fin);
		addAtFront(list, node);
		size--;
	}

	fclose(fin);
	return list;
}
