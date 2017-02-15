
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*

    list.c
        Contains functions to manipulate a doubly-linked list.

*/


/* private methods */

static struct node * reverse(struct node * L);
static void print(struct node * node);

struct list * createList()
{
    struct list * list = (struct list *) malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int getSize(struct list * L)
{
    if(L == NULL) {
        return 0;
    } else {
        return L->size;
    }
}

Boolean isEmpty(struct list * L)
{
    if (L == NULL || L->size == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void addAtFront(struct list * list, struct node * node)
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

void addAtRear(struct list * list, struct node * node)
{
}

struct node * removeFront(struct list * list)
{
    return NULL;
}

struct node * removeRear(struct list * list)
{
    return NULL;
}

struct node * removeNode(struct list * list, struct node * node)
{
    return NULL;
}

struct node * search(struct list * list, int key)
{
    return NULL;
}

void reverseList(struct list * L)
{
}

static struct node * reverse(struct node * L)
{
    return NULL;
}

void printList(struct list * L)
{
    if (L) print(L->head);
}

static void print(struct node * node)
{
    char *output;

    while (node) {
        output = toString(node->data);
        printf("%s\n",output);
        free(output);
        node = node->next;
    }
    printf("NULL\n");
}


void freeList(struct list * L)
{
}


/**
    Checkpoint the whole list to disk so we can restore it later.
    @param list     a pointer to a list that needs to be checkpointed
    @paramsaveFile  pathename of the checkpoint file

    @return TRUE if checkpointing succeeds, FALSE otherwise
*/

#define MAX_MSG_LENGTH 1024

Boolean checkpointList(struct list *list, char *saveFile)
{
    struct node *node;
    FILE *fout;
    char errmsg[MAX_MSG_LENGTH];

    if (list == NULL) { return TRUE; }
    if (isEmpty(list)) { return TRUE; }
    if (saveFile == NULL) { return FALSE; }
    if (strlen(saveFile) == 0) { return FALSE; }

    /* Open the file for writing */
    fout = fopen(saveFile, "w");
    if (!fout) {
        sprintf(errmsg, "checkpointList: %s",saveFile);
        perror(errmsg);
        return FALSE; // throwing an exception and exiting is also an option here
    }

    /* First, write out the number of nodes we will be outputting so
     * we know how many to read back in. */
    fwrite(&(list->size), sizeof(int), 1, fout);

    /* Then, write out the nodes (starting with the tail in this case) */
    node = list->tail;
    while (node) {
        checkpointNode(node, fout);
        node = node->prev;
    }
    fclose(fout);
    return TRUE;
}



/**
    Restore the whole list from disk. This will only work if the
    list was saved with the checkpointList function. If you modify
    the checkpointList function, then this function would need to be
    modified as well.
    @param saveFile  pathename of the checkpoint file
    @param list      a pointer to the restored list
*/

struct list *restoreList(char *saveFile)
{
    int size;
    FILE *fin;
    struct list *list;
    struct node *node;
    char errmsg[MAX_MSG_LENGTH];

    if (saveFile == NULL) { return NULL; }
    if (strlen(saveFile) == 0) { return NULL; }

    /* Open the file for reading */
    fin = fopen(saveFile, "r");
    if (!fin) {
        sprintf(errmsg, "restoreList: %s",saveFile);
        perror(errmsg);
        return NULL; // throwing an exception and exiting is also an option here
    }

    /* First, figure out how many nodes we wrote */
    fread(&size, sizeof(int), 1, fin);
    if (size <= 0) { return NULL; }
    printf("restore: list size = %d\n", size);

    /* Now, re-create the list */
    list = createList();
    while (size > 0) {
        node = restoreNode(fin);
        addAtFront(list, node);
        size--;
    }

    fclose(fin);
    return list;
}
