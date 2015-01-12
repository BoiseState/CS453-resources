
#include <stdlib.h>
#include <stdio.h>
#include <List.h>
#include <Node.h>

Boolean equals(const void *obj, const void *other) 
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
	sprintf(buf, " %d ", *object);
	return buf;
}

void freeObject(const void *obj) 
{ 
    free((void*)obj); // Since this is a pointer to a native type,
                      // not a struct, we need to cast it to avoid 
                      // a warning for modifying a const. This is
                      // okay and we are just assuring the compiler
                      // we know what we are doing.
}

int main(int argc, char **argv)
{
	int i, n;
	ListPtr list;
	NodePtr node;
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
