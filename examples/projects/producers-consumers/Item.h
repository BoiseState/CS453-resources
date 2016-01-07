
#ifndef __ITEM_H
#define __ITEM_H

#include <malloc.h>
#include <stdio.h>

typedef struct item Item;
typedef struct item * ItemPtr;

struct item {
	int id;
	int producer;
};

ItemPtr createItem(int index, int producer);
int compareToItem(const void *, const void *);
char *toStringItem(const void *);
void freeItem(const void *);



#endif /* __ITEM_H */
