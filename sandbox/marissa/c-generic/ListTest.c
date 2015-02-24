#include "List.h"

int main()
{

	// allocates a new list.
	struct list *list = createList();

	int i;
	for(i = 0; i <10; i++) {

		addAtFront(list, i);
	}

	printList(list);
}
