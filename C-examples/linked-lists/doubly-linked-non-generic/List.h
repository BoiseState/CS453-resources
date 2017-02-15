/*
    List.h: Defines the interface for a doubly-linked list.
*/

#ifndef __LIST_H
#define __LIST_H

#include "Node.h"

struct list {
    int size;
    struct node *head;
    struct node *tail;
};

/* prototypes of public methods */

/**
 * Constructor: Allocates a new List object and initializes its members.
 * <code>(size = 0; head = NULL, tail = NULL)</code>.
 *
 * @return a pointer to the allocated list.
 */
struct list* createList();

/**
 * Frees all elements of the given list and the <code>struct list *</code> itself.
 * Does nothing if list is <code>NULL</code>.
 *
 * @param list a pointer to a <code>struct list</code>.
 */
void freeList(struct list *list);

/**
 * Returns the size of the given list. Returns 0 if the list is <code>NULL</code>.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @return The current size of the list.
 */
int getSize(const struct list *list);

/**
 * Checks if the list is empty.
 *
 * @param  list a pointer to a <code>struct list</code>.
 * @return true if the list is empty; false otherwise.
 */
int isEmpty(const struct list *list);

/**
 * Adds a node to the front of the list. After this method is called,
 * the given node will be the head of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @param node a pointer to the node to add.
 */
void addAtFront(struct list *list, struct node *node);

/**
 * Adds a node to the rear of the list. After this method is called,
 * the given node will be the tail of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @param node a pointer to the node to add.
 */
void addAtRear(struct list *list, struct node *node);

/**
 * Removes the node from the front of the list (the head node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @return a pointer to the node that was removed.
 */
struct node* removeFront(struct list *list);

/**
 * Removes the node from the rear of the list (the tail node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @return a pointer to the node that was removed.
 */
struct node* removeRear(struct list *list);

/**
 * Removes the node pointed to by the given node pointer from the list and returns
 * the pointer to it. Assumes that the node is a valid node in the list. If the node
 * pointer is NULL, the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @param node a pointer to the node to remove.
 * @return a pointer to the node that was removed.
 */
struct node* removeNode(struct list *list, struct node *node);

/**
 * Searches the list for a node with the given obj and returns the pointer to the
 * found node. The search method should call the equals function pointer that was
 * provided by the user of this library.
 *
 * @param list a pointer to a <code>struct list</code>.
 * @param the object to search for.
 * @return a pointer to the node that was found. Or <code>NULL</code> if a node with the given obj was not
 * found or the list is <code>NULL</code> or empty.
 */
struct node* search(const struct list *list, const int value);

/**
 * Reverses the order of the given list.
 *
 * @param list a pointer to a <code>struct list</code>.
 */
void reverseList(struct list *list);

/**
 * Prints the list.
 *
 * @param list a pointer to a <code>struct list</code>.
 */
void printList(const struct list* list);


#endif /* __LIST_H */

