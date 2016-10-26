
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "record.h"

/**
 * Reads the next record from the given file.
 * @param r The record to read into. Must be allocated.
 * @param fin The file handle to read from.
 * @return The number of records read on success, negative value otherwise.
 */
static int read_record(struct record *r, FILE *fin)
{
    int chars = 0;
    chars = fscanf(fin, "%d %lf %lf %lf\n", &(r->key), &(r->value1), &(r->value2), &(r->value3));
    return (chars > 0) ? 1 : -1;
}


/**
 * Reads the n records from the given file into the array pointed to by r.
 * @param r The array to read records into. Must be allocated.
 * @param n The number of records to read.
 * @param fin The file handle to read from.
 * @return The number of records read.
 */
static int read_records(struct record *r, unsigned int n, FILE *fin)
{
    int i;
    for(i=0; i < n; i++) {
        if(read_record(r, fin) != 1)
            break;
        r++;
    }
    return i;
}

int main(int argc, char **argv)
{
    const char *filename = "data.txt";
    FILE *fin;
    unsigned int n;
    int read;
    struct record *records;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <number records>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);

    fin = fopen(filename, "r");
    if (!fin) {
        perror(filename);
        exit(errno);
    }

    fprintf(stderr, "Reading %d records...\n", n);

    records = (struct record *) malloc(sizeof(struct record) * n);
    read = read_records(records, n, fin);
    if(read != n) {
        fprintf(stderr, "Failed to read %d records. Found %d\n", n, read);
    }
    print_records(records, read);
    free(records);

    fclose(fin);

    return 0;
}

