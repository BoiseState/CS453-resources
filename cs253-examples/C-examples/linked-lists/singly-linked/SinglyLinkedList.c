/*
 * SinglyLinkedList.c
 * Contains a basic set of functions to manipulate a linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

struct list *createList() {

	struct list *myList = (struct list *) malloc(sizeof(struct list));
	myList->size = 0;
	myList->head = NULL;
	return myList;
}

struct list *addAtFront(struct list *myList, struct node *newNode)
{
    if (newNode == NULL) return myList;
    if (myList->head == NULL) {
        myList->head = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = myList->head;
        myList->head = newNode;
    }
	myList->size++;
    return myList;
}


struct list *reverseList(struct list *myList)
{
	struct node *head = myList->head;
    struct node *list = NULL;
    while (head) {
        struct node *tmp = head;
        head = head->next;
        tmp->next = list;
        list = tmp;
    }
	myList->head = list;
    return myList;
}


void printList(struct list *myList)
{
	struct node *head = myList->head;

	printf("List: %d elements\n", myList->size);
    while (head) {
        printf(" %d -->",head->item);
        head = head->next;
    }
    printf(" NULL \n");
}


