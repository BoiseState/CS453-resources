/*
 * SinglyLinkedList.c
 * Contains a basic set of functions to manipulate a linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

struct node *addAtFront(struct node *head, struct node *node)
{
	if (node == NULL) return head;
	if (head == NULL) {
		head = node;
		node->next = NULL;
	} else {
		node->next = head;
		head = node;
	}
	return head;
}


struct node* reverseList(struct node *head)
{
	struct node *list = NULL;
	while (head) {
		struct node *tmp = head;
		head = head->next;
		tmp->next = list;
		list = tmp;
	}
	return list;
}


void printList(struct node *head)
{
	while (head) {
		printf(" %d -->",head->item);
		head = head->next;
	}
	printf(" NULL \n");
}


