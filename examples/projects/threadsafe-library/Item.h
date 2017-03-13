
#ifndef __ITEM_H
#define __ITEM_H

#include <malloc.h>
#include <stdio.h>


struct item {
	int id;
	int producer;
};

struct item *createItem(int index, int producer);
int compareToItem(const void *, const void *);
char *toStringItem(const void *);
void freeItem(void *);



#endif /* __ITEM_H */
