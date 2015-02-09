#include <stdlib.h>
#include <stdio.h>
#include <List.h>
#include <Node.h>

int equals(const void *obj, const void *other)
{
	int *o1 = (int *) obj;
	int *o2 = (int *) other;
	return *o1 == *o2;
}

char *toString(const void *obj)
{
	int *object = (int *) obj;
	const int MAX_DIGITS = 10; /* maximum digits in an int */
	char *buf;
	buf = (char *) malloc(sizeof(char)*MAX_DIGITS);
	snprintf(buf,MAX_DIGITS, " %d ", *object);
	return buf;
}

void freeObject(void *obj)
{
    free(obj);
}

int main(int argc, char **argv)
{
	int i, n;
	struct list *list;
	struct node *node;
	int *object;

	n=1000;
	list = createList(equals, toString, freeObject);
	for (i=0; i<n; i++) {
		object = (int *) malloc(sizeof(int));
		*object = i;
		node = createNode(object);
		addAtFront(list, node);
	}

	printList(list);
	freeList(list);
	exit(0);
}
