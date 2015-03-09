#include "List.h"
#include "Dog.h" // We want to include the dog header in the test
                    // file, NOT Node.h as we had in our previous version.
		    // We want to completely decouple our dog from our
		    // list implementation.

int main(int argc, char *argv[])
{
	// allocates a new list.
	struct list *list = createList(equals, toString, freeDog);
	struct node *node;

	// Add nodes to the list.
	int i;
	for(i = 0; i < 10; i++) {
		struct dog *dog = createDog(i, "fido");
		node = createNode(dog);
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
