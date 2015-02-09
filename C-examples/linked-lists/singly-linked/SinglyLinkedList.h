
#ifndef __SINGLYLINKEDLIST_H
#define __SINGLYLINKEDLIST_H
/* C-examples/singlyLinkedList/SinglyLinkedList.h */
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct node *NodePtr;
typedef int ItemType;

struct node {
	ItemType  item;
	NodePtr next;
};

/* prototypes */

/**
  Add a node to the front  of the list.
  @param L pointer to front of the list
  @param node the new node to add
  @return the current pointer to the front of the list
 */
NodePtr addAtFront(NodePtr L, NodePtr node);


/**
  Reverse the list in place.
 
  @param L pointer to front of the list
  @return pointer to the front of the reversed list
 */
NodePtr reverseList(NodePtr L);

/**
  Print the list from start to end.
  @param L pointer to front of the list
*/
void printList(NodePtr L);


#endif /* __SINGLYLINKEDLIST_H */ 
