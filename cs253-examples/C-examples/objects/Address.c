
/* C-examples/objects/Address.c */

#include "Address.h"

#define PADDING (4+5+10)

static int getLength(Address this)
{
    return strlen(this->name) + strlen(this->streetAddress) + 
           strlen(this->city) + strlen(this->state) + PADDING;
}

Address createAddress(char *name, char *streetAddress, char *city,
                      char *state, int zip, char *(*printAddress)(struct address *))
{
    Address temp = (Address) malloc(sizeof(address));
    temp->name = (char *) malloc(sizeof(char)* (strlen(name) + 1));
    temp->streetAddress = (char *) malloc(sizeof(char)*(strlen(streetAddress) + 1));
    temp->city = (char *) malloc(sizeof(char) * (strlen(city) + 1));
    temp->state = (char *) malloc(sizeof(char) * (strlen(state) + 1));
    strcpy(temp->name, name);
    strcpy(temp->streetAddress, streetAddress);
    strcpy(temp->city, city);
    strcpy(temp->state, state);
    temp->zip = zip;
    if(printAddress == NULL)
        temp->toString = printDefault;
    else
        temp->toString = printAddress;
    return temp;
}

char *printMultiLine(Address this)
{
    int len = getLength(this);
    char *temp = (char *) malloc(sizeof(char) * len);
    snprintf(temp, len, "%s\n%s\n%s, %s, %d\n", this->name,
             this->streetAddress, this->city, this->state, this->zip);
    return temp;
}

char *printOneLine(Address this)
{
    int len = getLength(this);
    char *temp = (char *) malloc(sizeof(char)* len);
    snprintf(temp, len, "%s, %s, %s, %s %d\n", this->name,
             this->streetAddress, this->city, this->state, this->zip);
    return temp;
}

char *printDefault(Address address)
{
    return "default";
}










