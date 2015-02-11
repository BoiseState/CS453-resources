#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Linked list node
 */
struct node {
	int item;
	struct node *next;
};

/**
  Add a node to the front  of the list.
  @param list pointer to front of the list
  @param node the new node to add
  @return the current pointer to the front of the list
 */
struct node* addAtFront(struct node *head, struct node *node);


/**
  Reverse the list in place.

  @param list pointer to front of the list
  @return pointer to the front of the reversed list
 */
struct node* reverseList(struct node *head);

/**
  Print the list from start to end.
  @param list pointer to front of the list
*/
void printList(struct node *head);


#endif /* __SINGLYLINKEDLIST_H */
