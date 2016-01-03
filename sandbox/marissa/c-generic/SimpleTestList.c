#include "List.h"
#include "Object.h" // We want to include the object header in the test
// file, NOT Node.h as we had in our previous version.
// We want to completely decouple our object from our
// list implementation.

int main(int argc, char *argv[])
{
    // allocates a new list.
    struct list *list = createList(equals, toString, freeObject);
    struct node *node;

    // Add nodes to the list.
    int i;
    for(i = 0; i < 10; i++) {
        struct object *object = createObject(i, "");
        node = createNode(object);
        addAtFront(list, node); //modify to add node instead.
    }

    printList(list);

    /* struct node *remove = removeFront(list); */
    /* remove->next->next = NULL; */
    /*  */
    /* printList(list); */

    freeList(list);

    return 0;
}
