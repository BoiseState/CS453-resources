


#ifndef  __RECORD_H
#define  __RECORD_H

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

typedef struct record Record;
typedef struct record * RecordPtr;

struct record {
    long int key;
    double value1;
    double value2;
    double value3;
};

char *toString(RecordPtr record);

#endif /*  __RECORD_H */
