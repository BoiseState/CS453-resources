#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>


/* 
 * The overall list structure
 */
struct list {
	int size;
	struct node *head;
};


/*
 * Linked list node
 */
struct node {
    int item;
    struct node *next;
};

/**
  Create an empty list.

  @return pointer to the list structure
 */
struct list *createList();

/**
  Add a node to the front  of the list.
  @param list pointer to front of the list
  @param node the new node to add
  @return the current pointer to the front of the list
 */
struct list *addAtFront(struct list *list, struct node *node);


/**
  Reverse the list in place.

  @param list pointer to front of the list
  @return pointer to the front of the reversed list
 */
struct list *reverseList(struct list *list);


/**
  Print the list from start to end.
  @param list pointer to front of the list
*/
void printList(struct list *list);

#endif /* __SINGLYLINKEDLIST_H */
