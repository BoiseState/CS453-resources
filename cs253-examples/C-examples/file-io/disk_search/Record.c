
#include "Record.h"

#define MAXLEN 128

char *toString(RecordPtr record)
{
    char *buffer;

    buffer = (char *) malloc(sizeof(char) * MAXLEN);
    sprintf(buffer, "key=%ld values=[%lf, %lf, %lf]\n",
            record->key, record->value1, record->value2, record->value3);
    return buffer;
}
