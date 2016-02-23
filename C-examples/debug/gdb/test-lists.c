
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int main(int argc, char **argv)
{
    int i;
    int n;
    NodePtr L, prev, list;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <list size> \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);

    L = NULL;
    prev = L;
    for (i=n; i>0; i--) {
        L = (NodePtr) malloc(sizeof(struct node));
        if (L == NULL) {
            printf("Error allocating node for linked list\n");
            exit(1);
        }
        L->next = prev;
        L->item = i;
        prev = L;
    }

    PrintList(L);
    list=ReverseList(L);
    PrintList(list);
    exit(0);
}

