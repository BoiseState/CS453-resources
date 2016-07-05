
/* C-examples/objects/Address.h */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct address address;
typedef struct address * Address;

struct address {
    char *name;
    char *streetAddress;
    char *city;
    char *state;
    int zip;

    char * (*toString)(struct address *);
};

Address createAddress(char *, char *, char *, char *, int,
                      char *(*printAddress)(struct address *));
char *printMultiLine(Address);
char *printOneLine(Address);
char *printDefault(Address);

#endif /* ADDRESS_H */
