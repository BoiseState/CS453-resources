#ifndef __OBJECT_H
#define __OBJECT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_DIGITS 10

struct object {
    int key;
    char *data;
};

struct object* createObject (const int, const char *);
char *toString(const void *);
void freeObject(void *);
int equals(const void *,const void *);


#endif /* __OBJECT_H */
