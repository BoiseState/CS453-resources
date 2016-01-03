#include "List.h"

/**
 * Constructor
 */
struct list *createList(int (*equals)(const void *, const void *),
                        char *(*toString)(const void *),
                        void (*freeObject)(const void *))
{
    struct list *list = (struct list *) malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;

    list->equals = equals;
    list->toString = toString;
    list->freeObject = freeObject;

    return list;
}

/**
 * Frees the list.
 */
void freeList(struct list *list)
{
    if(list == NULL) return;

    struct node *node = list->head;
    while(node) { // free all the nodes
        struct node *temp = node->next;
        freeNode(node, list->freeObject);
        node = temp;
    }

    free(list);
    list = NULL; // can't do this if parameter is const, but its ok.
}

/**
 * Add to the front of the list.
 */
void addAtFront(struct list *list, struct node* node)
{
    if(list == NULL) return;
    if(node == NULL) return;

    if(list->head == NULL) {           // case 1. list is currently empty.
        list->head = node;
    } else {                           // case 2. it's not empty.
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

/**
 * Removes the head node.
 * Show dangling pointers.
 */
struct node* removeFront(struct list* list)
{
    if(list == NULL) return NULL;
    if(list->head == NULL) return NULL;

    struct node *node = list->head;
    list->head = node->next;

    // Don't leave any dangling pointers!!
    node->next = NULL;

    return node;
}

/**
 * Searches the list for the node with the given object. Returns
 * it if found, NULL otherwise.
 */
struct node* searchList(struct list* list, void *object)
{
    if(list == NULL) return NULL;
    if(object == NULL) return NULL;

    struct node *node = list->head;
    while(node != NULL) {
        // check for equality.
        if((*list->equals)(node->object,object)) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/**
 * TODO: implement me.
 */
void printList(struct list *list)
{
    if(list != NULL) {
        struct node *node = list->head;
        while(node != NULL) {
            //print node.
            printNode(node, list->toString);
            printf("-->");
            node = node->next;
        }
    }
    printf("NULL\n");
}
