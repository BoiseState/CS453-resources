#include <stdlib.h>
#include <stdio.h>
#include <List.h>
#include <Node.h>

int main(int argc, char **argv)
{
    int i, n;
    struct list *list;
    struct node *node;

    n=10;
    list = createList();
    for (i=0; i<n; i++) {
        node = createNode(i);
        addAtFront(list, node);
    }

    printList(list);
    freeList(list);
    exit(0);
}
