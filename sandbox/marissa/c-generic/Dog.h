#ifndef __OBJECT_H
#define __OBJECT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_DIGITS 4

struct dog {
    int id;
    char *name;
};

struct dog* createDog (const int, const char *);
char *toString(const void *);
void freeDog(const void *);
int equals(const void *, const void *);


#endif /* __OBJECT_H */
