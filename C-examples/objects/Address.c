
/* C-examples/objects/Address.c */

#include "Address.h"

static int getLength(Address this)
{
	return strlen(this->name)+strlen(this->streetAddress)+
				strlen(this->city)+strlen(this->state)+4+5+10;
}

//Address createAddress(char *name, char *streetAddress, char *city,
//                      char *state, int zip, char * (*toString)(Address))
Address createAddress(char *name, char *streetAddress, char *city,
                      char *state, int zip)
{
	Address temp = (Address) malloc(sizeof(address));
	temp->name = (char *) malloc(sizeof(char)*(strlen(name)+1));
	temp->streetAddress = (char *) malloc(sizeof(char)*(strlen(streetAddress)+1));
	temp->city = (char *) malloc(sizeof(char)*(strlen(city)+1));
	temp->state = (char *) malloc(sizeof(char)*(strlen(state)+1));
	strcpy(temp->name, name);
	strcpy(temp->streetAddress, streetAddress);
	strcpy(temp->city, city);
	strcpy(temp->state, state);
	temp->zip = zip;
	temp->toString = printMultiLine;
	//temp->toString = toString;
	return temp;
}

char *printMultiLine(Address this)
{
	int len = getLength(this);
	char * temp = (char *) malloc(sizeof(char)*len);
	snprintf(temp, len, "%s\n%s\n%s, %s, %d\n", this->name,
				this->streetAddress, this->city, this->state, this->zip);
	return temp; 
}

char *printOneLine(Address this)
{
	int len = getLength(this);
	char * temp = (char *) malloc(sizeof(char)*len);
	snprintf(temp, len, "%s, %s, %s, %s %d\n", this->name,
				this->streetAddress, this->city, this->state, this->zip);
	return temp; 
}

