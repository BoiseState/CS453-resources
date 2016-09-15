
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "common.h"
#include "Record.h"
#include "ExternalSearch.h"

char *program;
const int MAX_KEY = 100000;
double getMilliseconds();
#define BINARY 1
#define LINEAR 2


/**
 * @brief See function name
 *
 * @param dataFile - The file to search
 * @param n - The number of searches to conduct
 * @param searchType - The type of search BINARY or LINEAR
 */
void conduct_random_searches(FILE *dataFile, long int n, int searchType)
{
    long int i;
    unsigned long int key;
    Record *record;
    char *buffer;

    for (i=0; i<n; i++) {
        key = (unsigned long int) random() % MAX_KEY;
        if (DEBUG >= 1) {
            printf("\nSearching for key = %ld\n\n", key);
        }
        switch (searchType) {
        case BINARY:
            record = extBinarySearch(dataFile, key);
            break;
        case LINEAR:
            record = extLinearSearch(dataFile, key);
            break;
        }

        if (DEBUG >= 1) {
            if (record) {
                buffer = toString(record);
                printf("%s\n", buffer);
                printf("found: record with key %ld\n", key);
                free(record);
                free(buffer);
            } else {
                printf("not found: record with key %ld\n", key);
            }
        }
    }
}


void print_usage(int argc, char **argv)
{
    fprintf(stderr, "Usage: %s <data file name> <number of searches> [binary|linear]\n", program);
    exit(1);
}



int main (int argc, char **argv)
{
    int n;
    long int count;
    FILE *dataFile;
    double startTime, totalTime;
    int searchType;

    program = argv[0];

    if (argc < 3 || argc > 5) {
        print_usage(argc, argv);
    }
    n = atoi(argv[2]);
    dataFile = fopen(argv[1], "r");
    if (!dataFile) {
        perror(program);
        exit(errno);
    }
    searchType = BINARY;
    if (argc == 4) {
        if (argv[3][0] == 'b')
            searchType = BINARY;
        else if (argv[3][0] == 'l')
            searchType = LINEAR;
        else {
            fprintf(stderr, "Usage: choose correct search type!\n");
            print_usage(argc, argv);
        }
    }

    fseek(dataFile, 0, SEEK_END);
    count = ftell(dataFile);
    count = count/sizeof(Record);
    if (DEBUG >= 1) {
        fprintf(stderr, "data file has %ld records\n", count);
    }

    startTime = getMilliseconds();
    conduct_random_searches(dataFile, n, searchType);
    totalTime = getMilliseconds() - startTime;
    if (searchType == BINARY)
        fprintf(stderr, "Elapsed time for %d binary searches = %8.2f seconds\n", n, totalTime/1000.0);
    else if (searchType == LINEAR)
        fprintf(stderr, "Elapsed time for %d binary searches = %8.2f seconds\n", n, totalTime/1000.0);

    fclose(dataFile);
    exit(0);
}

/* vim: set ts=4: */
