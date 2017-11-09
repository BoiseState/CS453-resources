#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main(int argc, char **argv)
{
    int i;
    int n;
    struct list *myList;
    struct node *node;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <list size> \n",argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);

	myList = createList();
    for (i=0; i<n; i++) {
        node = (struct node *) malloc(sizeof(struct node));
        if (node == NULL) {
            printf("Error allocating node for linked list\n");
            exit(1);
        }
        node->item = i;
        myList = addAtFront(myList, node);
    }

    printList(myList);
    myList=reverseList(myList);
    printList(myList);

    return 0;
}

