#include "Dog.h"
#include <string.h>

struct dog* createDog(const int id, const char *name)
{
    struct dog* newDog = (struct dog*) malloc (sizeof(struct dog));
    newDog->id = id;
    newDog->name = (char *) malloc(sizeof(char)*(strlen(name)+1));
    strcpy(newDog->name, name);
    return newDog;
}

int equals(const void *dog, const void *other)
{
    struct dog* o1 = (struct dog*) dog;
    struct dog* o2 = (struct dog*) other;
    return o1->id == o2->id;
}

char *toString(const void *dog)
{
    struct dog *mydog = (struct dog *) dog;
    char *temp;
    int max_name = strlen(mydog->name)+1;
    max_name += MAX_KEY_DIGITS;
    temp = (char *)malloc(max_name);
    //print into our buffer safely
    snprintf(temp, max_name, "[%d] %s", mydog->id, mydog->name);
    return temp;
}

void freeDog(const void *dog)
{
    struct dog* mydog = (struct dog*) dog;
    if (mydog == NULL) return;
    free(mydog->name);
    free(mydog);
}
