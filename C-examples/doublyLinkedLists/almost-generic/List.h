#ifndef __LIST_H
#define __LIST_H

#include "common.h"
#include "Node.h"

typedef struct list List;
typedef struct list *ListPtr;

struct list {
    int size;
    NodePtr head;
    NodePtr tail;
};

/**
 * Allocates a new List object and initializes its members.
 * <code>(size = 0; head = NULL, tail = NULL)</code>.
 *
 * @return a pointer to the allocated list.
 */
ListPtr createList();

/**
 * Frees all elements of the given list and the <code>ListPtr</code> itself. 
 * Does nothing if L is <code>NULL</code>.
 *
 * @param L a pointer to a <code>List</code>.
 */
void freeList(const ListPtr L);

/**
 * Returns the size of the given list.
 *
 * @param L a pointer to a <code>List</code>.
 * @return The current size of the list.
 */
int getSize(const ListPtr L);

/**
 * Checks if the list is empty.
 *
 * @param  L a pointer to a <code>List</code>.
 * @return true if the list is empty; false otherwise.
 */
Boolean isEmpty(const ListPtr L);

/**
 * Adds a node to the front of the list. After this method is called,
 * the given node will be the head of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to add.
 */
void addAtFront(ListPtr list, NodePtr node);

/**
 * Adds a node to the rear of the list. After this method is called,
 * the given node will be the tail of the list. (Node must be allocated
 * before it is passed to this function.) If the list and/or node are NULL,
 * the function will do nothing and return.
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to add.
 */
void addAtRear(ListPtr list, NodePtr node);

/**
 * Removes the node from the front of the list (the head node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>List</code>.
 * @return a pointer to the node that was removed.
 */
NodePtr removeFront(ListPtr list);

/**
 * Removes the node from the rear of the list (the tail node) and returns
 * a pointer to the node that was removed. If the list is NULL or empty,
 * the function will do nothing and return NULL.
 *
 * @param list a pointer to a <code>List</code>.
 * @return a pointer to the node that was removed.
 */
NodePtr removeRear(ListPtr list);

/**
 * Removes the node pointed to by the given node pointer from the list and returns
 * the pointer to it. Assumes that the node is a valid node in the list. If the node 
 * pointer is NULL, the function will do nothing and return NULL. 
 *
 * @param list a pointer to a <code>List</code>.
 * @param node a pointer to the node to remove.
 * @return a pointer to the node that was removed.
 */
NodePtr removeNode(ListPtr list, NodePtr node);

/**
 * Searches the list for a node with the given key and returns the pointer to the
 * found node.
 *
 * @param list a pointer to a <code>List</code>.
 * @param key the value of the key to search for.
 * @return a pointer to the node that was found. Or <code>NULL</code> if a node with the given key is not 
 * found or the list is <code>NULL</code> or empty.
 */
NodePtr search(const ListPtr list, const int key);

/**
 * Reverses the order of the given list.
 *
 * @param list a pointer to a <code>List</code>.
 */
void reverseList(ListPtr L);

/**
 * Prints the list.
 *
 * @param list a pointer to a <code>List</code>.
 */
void printList(const ListPtr L);


#endif /* __LIST_H */
