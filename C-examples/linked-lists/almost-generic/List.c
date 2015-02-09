#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListPtr createList()
{
    ListPtr list;
    list = (ListPtr) malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void freeList(const ListPtr L)
{
}

int getSize(const ListPtr L)
{
    return 0;
}

Boolean isEmpty(const ListPtr L)
{
    return FALSE;
}

void addAtFront(ListPtr list, NodePtr node)
{
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

NodePtr search(const ListPtr list, const int key)
{
    return NULL;
}

void reverseList(ListPtr L)
{
}

void printList(const ListPtr L)
{
}
