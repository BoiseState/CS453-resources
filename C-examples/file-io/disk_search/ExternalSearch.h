
#ifndef  __EXTERNALSEARCH_H
#define  __EXTERNALSEARCH_H

#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "Record.h"

/**
    Search for a record with the input key value in the specified
    binary file on the disk. Uses binary search to minimize the number
    of disk reads.

    @param dataFile  file pointer to an open file.
        @param key       integer key value to use for searching

    @return  pointer to a record structure if search is successful
             otherwise a NULL pointer .
*/
RecordPtr extBinarySearch(FILE *dataFile, unsigned long int key);


/**
    Search for a record with the input key value in the specified binary
    file on the disk. Uses linear search to find the record. This will
    work in unsorted files as well as sorted files.

    @param dataFile  file pointer to an open file.
        @param key       integer key value to use for searching

    @return  pointer to a record structure if search is successful
             otherwise a NULL pointer .
*/
RecordPtr extLinearSearch(FILE *dataFile, unsigned long int key);

#endif /*  __EXTERNALSEARCH_H */
