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
	char *temp;
	int max_data = strlen(myobj->data)+1;
	max_data += MAX_KEY_DIGITS;
	temp = (char *)malloc(max_data);
	//print into our buffer safely
	snprintf(temp, max_data, "[%d] %s", myobj->key, myobj->data);
	return temp;
}

void freeObject(void *obj)
{
	struct object* myobj = (struct object*) obj;
	if (myobj == NULL) return;
	free(myobj->data);
	free(myobj);
}
