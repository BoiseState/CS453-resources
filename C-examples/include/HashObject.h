
#ifndef __HASHOBJECT_H
#define __HASHOBJECT_H

#include <stdlib.h>

typedef struct hashobject HashObject;
typedef struct hashobject * HashObjectPtr;

struct hashobject {
	int frequency;
	void *obj;
};

HashObjectPtr createHashObject(void *obj);
void freeHashObject(HashObjectPtr hobj, void (*freeObject)(void *obj));

#endif /* __HASHOBJECT_H */
