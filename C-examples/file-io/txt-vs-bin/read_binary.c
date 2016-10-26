
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "record.h"

/**
 * Reads the n records from the given file into the array pointed to by r.
 * @param r The array to read records into. Must be allocated.
 * @param n The number of records to read.
 * @param fin The file handle to read from.
 */
static int read_records(struct record *r, unsigned int n, FILE *fin)
{
    return fread(r, sizeof(struct record), n, fin);
}

/**
 * Reads the ith record from the given file.
 * @param r The record to read into. Must be allocated.
 * @param i The index of the record in the file.
 * @param fin The file handle to read from.
 */
static int read_record(struct record *r, unsigned int i, FILE *fin)
{
    fseek(fin, sizeof(struct record) * i, SEEK_SET);
    return fread(r, sizeof(struct record), 1, fin);
}

int main(int argc, char **argv)
{
    const char *filename = "data.bin";
    FILE *fin;
    unsigned int n;
    int read;
    struct record *records;


    fin = fopen(filename, "r");
    if (!fin) {
        perror(filename);
        exit(errno);
    }

    n = num_records(fin);

    fprintf(stderr, "Reading %d records...\n", n);

    records = (struct record *) malloc(sizeof(struct record) * n);
    read = read_records(records, n, fin);
    if(read != n) {
        fprintf(stderr, "Failed to read %d records\n", n);
    } else {
        print_records(records, n);
    }
    free(records);

    /* uncomment to read one record. */
    /* struct record record; */
    /* unsigned int i = 5; */
    /* fprintf(stderr, "Reading record %d...\n", i); */
    /*  */
    /* read = read_record(&record, i, fin); */
    /* if(read != 1) { */
    /*  fprintf(stderr, "Failed to read record %d\n", i); */
    /* } else { */
    /*  print_record(&record); */
    /* } */

    fclose(fin);

    return 0;
}

