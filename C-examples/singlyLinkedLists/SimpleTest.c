
#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"


int main(int argc, char **argv)
{	
	int i;
	int n;
	NodePtr list, node;

	if (argc != 2) {
			fprintf(stderr, "Usage: %s <list size> \n",argv[0]);
			exit(1);
	}
	n = atoi(argv[1]);

	list = NULL;
	for (i=0; i<n; i++) {
		node = (NodePtr) malloc(sizeof(Node));
		if (node == NULL) {
			printf("Error allocating node for linked list\n");	
			exit(1);
		}
		node->item = i;
		list = addAtFront(list, node);
	}

	if (n <= 10)
        printList(list);
    else
        printf("List too long...not printing.\n");

    list=reverseList(list);

    if (n <= 10)
        printList(list);
    else
        printf("List too long...not printing.\n");

	return 0;
}

