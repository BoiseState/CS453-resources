

#ifndef __OBJECT_H
#define __OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXPID_DIGITS 20


typedef struct object  Object;
typedef struct object *ObjectPtr;

struct object {
	int key;
	char *data;
};

ObjectPtr createObject (const int, const char *);

char *toString(const void *);
void freeObject(const void *);
Boolean equals(const void *,const void *);


#endif /* __OBJECT_H */
