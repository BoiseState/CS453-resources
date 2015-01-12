#include "Object.h"


ObjectPtr createObject(const int key, const char *data)
{
	ObjectPtr newObject = (ObjectPtr) malloc (sizeof(Object));
	newObject->key = key;
	newObject->data = (char *) malloc(sizeof(char)*(strlen(data)+1));
	strcpy(newObject->data, data); 
	return newObject;
}

Boolean equals(const void *obj, const void *other)
{
	ObjectPtr o1 = (ObjectPtr) obj;
	ObjectPtr o2 = (ObjectPtr) other;
	return o1->key == o2->key;
}

char *toString(const void *obj)
{
	ObjectPtr myobj = (ObjectPtr) obj;
	char *temp;
	temp = (char *)malloc(sizeof(char)*strlen(myobj->data)+1+MAXPID_DIGITS+4);
	sprintf(temp, "[%d] %s", myobj->key, myobj->data);
	return temp;
}

void freeObject(const void *obj)
{
	ObjectPtr myobj = (ObjectPtr) obj;
	if (myobj == NULL) return;
	free(myobj->data);
	free(myobj);
}
