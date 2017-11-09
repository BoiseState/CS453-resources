#include "Object.h"
#include <string.h>

struct object* createObject(const int key, const char *data)
{
    struct object* newObject = (struct object*) malloc (sizeof(struct object));
    newObject->key = key;
    newObject->data = (char *) malloc(sizeof(char)*(strlen(data)+1));
    strcpy(newObject->data, data);
    return newObject;
}

int equals(const void *obj, const void *other)
{
    struct object* o1 = (struct object*) obj;
    struct object* o2 = (struct object*) other;
    return o1->key == o2->key;
}

char *toString(const void *obj)
{
    struct object* myobj = (struct object*) obj;

    // calculate and allocate enough space for output string
    int max_data_len = strlen(myobj->data)+1;
    max_data_len += MAX_KEY_DIGITS;
    max_data_len += 3; // for [] and space
    char *temp = (char *) malloc(sizeof(char) * max_data_len);

    //print into our buffer safely
    snprintf(temp, max_data_len, "[%d] %s", myobj->key, myobj->data);
    return temp;
}

void freeObject(void *obj)
{
    struct object* myobj = (struct object*) obj;
    if (myobj == NULL) return;
    free(myobj->data);
    free(myobj);
}
