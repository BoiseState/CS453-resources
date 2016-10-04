#include <stdlib.h>
#include <stdio.h>
/* We can use the < > notation on Node.h and List.h
 * because we set the include directory in the Makefile */
#include <List.h>
#include <Node.h>

/**
 * Creates a linked list of size n, prints it and frees it.
 */
int main(int argc, char **argv)
{
    int i, n;
	struct list *list; /* a pointer to the list itself */
    struct node *node; /* a pointer to a temp node */

	/* Read number of list elements from command-line. */
	if(argc != 2) {
		printf("Usage: %s <n>\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);

	/* Instantiate the linked list */
    list = createList();

	/* Fill the list with nodes (adding to front) */
    for(i = 0; i < n; i++) {
        node = createNode(i);
        addAtFront(list, node);
    }

	/* Print the list to the console. */
    printList(list);

	/* Free the memory before exiting. */
    freeList(list);

	return 0;
}
