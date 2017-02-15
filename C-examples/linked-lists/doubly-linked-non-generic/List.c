#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct list * createList()
{
    struct list *list;
    list = (struct list *) malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void freeList(struct list *list)
{
}

int getSize(const struct list *list)
{
    return 0;
}

int isEmpty(const struct list *list)
{
    return list->size == 0;
}

void addAtFront(struct list *list, struct node *node)
{
    if (list == NULL) return;
    if (node == NULL) return;
    list->size++;
    node->next = list->head;
    node->prev = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->head->prev = node;
        list->head = node;
    }
}

void addAtRear(struct list *list, struct node *node)
{
}

struct node* removeFront(struct list *list)
{
    return NULL;
}

struct node* removeRear(struct list *list)
{
    return NULL;
}

struct node* removeNode(struct list *list, struct node *node)
{
    return NULL;
}

struct node* search(const struct list *list, const int value)
{
    return NULL;
}

void reverseList(struct list *list)
{
}

void printList(const struct list *list)
{
    if (!list) return; //list was null!!
    struct node *temp = list->head;
    while (temp) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}
