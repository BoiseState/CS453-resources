
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/*

    lists.c
        Contains functions to manipulate a linked list.

 */


NodePtr ReverseList(NodePtr L)
{
    NodePtr list = NULL;
    while (L != NULL) {
        NodePtr tmp = L;
        L = L->next;
        tmp->next = list;
        list = tmp;
    }
    return list;
}

void PrintList(NodePtr L)
{
    int count = 0;
    while (L) {
        printf(" %d -->",L->item);
        L = L->next;
        count++;
    }
    printf(" NULL \n");
}



