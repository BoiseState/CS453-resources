
#include "ExternalSearch.h"

static long int numRecords(FILE *);

RecordPtr extBinarySearch(FILE *dataFile, unsigned long int key)
{
    /* the search window is low..high if we view the dataFile as an
       array of record strutures */
    long int low = 0;
    long int mid = 0;
    long int high = 0;
    long int pos = 0; /* offset into the file, in bytes */
    RecordPtr record;
    char *buffer;

    if (dataFile == NULL) return NULL;
    high = numRecords(dataFile);

    record = (RecordPtr) malloc(sizeof(Record));
    while (low <= high) {
        mid = (low+high)/2;
        pos = mid * sizeof(Record); /* calculate byte offset in the file */
        fseek(dataFile, pos, SEEK_SET);
        fread(record, sizeof(Record), 1, dataFile);
        if (DEBUG >= 2) {
            buffer = toString(record);
            fprintf(stderr, "low = %ld mid = %ld high = %ld\n", low, mid, high);
            fprintf(stderr, "====>record: %s", buffer);
            free(buffer);
        }
        if (record->key == key) {
            return record;
        } else if (record->key < key) {
            low = mid + 1;
        } else { /* record->key > key */
            high = mid - 1;
        }
    }
    free(record);
    return NULL;
}



RecordPtr extLinearSearch(FILE *dataFile, unsigned long int key)
{
    long int i = 0;
    long int count = 0;
    long int pos = 0; /* offset into the file, in bytes */
    RecordPtr record;

    if (dataFile == NULL) return NULL;
    count = numRecords(dataFile);

    record = (RecordPtr) malloc(sizeof(Record));
    for (i = 0; i < count; i++) {
        pos = i * sizeof(Record); /* calculate byte offset in the file */
        fseek(dataFile, pos, SEEK_SET);
        fread(record, sizeof(Record), 1, dataFile);
        if (record->key == key) {
            return record;
        }
    }
    free(record);
    return NULL;
}



static long int numRecords(FILE *dataFile)
{
    long int count = 0;

    /* figure out the size of the file in bytes */
    fseek(dataFile, 0, SEEK_END);
    count = ftell(dataFile);
    /* set high to number of records in the file */
    count = count/sizeof(Record);
    if (DEBUG >= 2) {
        fprintf(stderr, "data file has %ld records\n", count);
    }
    return count;
}

