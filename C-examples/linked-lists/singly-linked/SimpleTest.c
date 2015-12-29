#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main(int argc, char **argv) {
    int i;
    int n;
    struct node *list;
    struct node *node;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <list size> \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);

    list = NULL;
    for (i=0; i<n; i++) {
        node = (struct node*) malloc(sizeof(struct node));
        if (node == NULL) {
            printf("Error allocating node for linked list\n");
            exit(1);
        }
        node->item = i;
        list = addAtFront(list, node);
    }

    printList(list);

    list=reverseList(list);
    printList(list);

    return 0;
}

