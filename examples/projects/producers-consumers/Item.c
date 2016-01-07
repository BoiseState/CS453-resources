
#include "Item.h"

ItemPtr createItem(int index, int producer) 
{
	ItemPtr item = (ItemPtr) malloc(sizeof(Item));
	item->id = index; // this gets filled in by the pool
	item->producer = producer;
	return item;
}

int compareToItem(const void *obj1, const void *obj2)
{
	return ((ItemPtr)obj1)->id - ((ItemPtr)obj2)->id;
}

#define ITEM_STRING_SIZE 128

char *toStringItem(const void *obj)
{
	ItemPtr item = (ItemPtr) obj;
	char *buffer = (char *) malloc(sizeof(char)*ITEM_STRING_SIZE);
	sprintf(buffer, "%d from producer %d ", item->id, item->producer);
	return buffer;
}

void freeItem(const void *obj) 
{
	free((ItemPtr) obj);
}
