#include "List.h"

int main(int argc, char *argv[])
{
	// allocates a new list.
	struct list *list = createList();
	struct node *node;

	int i;
	for(i = 0; i < 10; i++) {
		node = createNode(i);
		addAtFront(list, node); //modify to add node instead.
	}

	printList(list);

	freeList(list);

	int id = 10;
	char *data = "hello";

	struct object *obj = createObject(10, data);

	return 0;
}
