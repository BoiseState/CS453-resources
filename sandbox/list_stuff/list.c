#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};


/**
 * @brief Prints off a node
 *
 * @param n the node to print
 */
void printNode(struct node* n)
{
    printf("data=%d\n", n->data);
}


/**
 * @brief Construct a new node with everything init'd correctly
 *
 * @param data the value to store in the node
 *
 * @return the allocated node
 */
struct node * createNode(int data)
{
    struct node *tmp =  malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

int main (int foo, char *bar[])
{
    //Create a node to represent the "head" of the list
    struct node *head =  createNode(-1);
    //Pointer to use for moving through the list
    struct node *curr = head;
    //for loop using C99 syntax
    for(int i =0; i<10; i++) {
        //(*curr).next = createNode(i);
        curr->next = createNode(i);
        //go to the next node in the list;
        curr = curr->next;
    }
    //Reset curr so we can go through the list
    curr = head;
    while(curr) {
        printNode(curr);
        curr = curr->next;
    }
    return 0;
}
