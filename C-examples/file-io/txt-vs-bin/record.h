#ifndef __RECORD_H
#define __RECORD_H

#include <stdio.h>

struct record {
    int key;
    double value1;
    double value2;
    double value3;
};

extern const int MAX_KEY;

/**
 * Generates a file of random records.
 * @param n The number of records that will be generated.
 * @param filename The name of the output file.
 * @param write_record A pointer to the function that will write each record.
 */
void generate_record_file(const int unsigned n, const char *filename, void (*write_record)(struct record *, FILE *fout));

/**
 * Fills the given record structure with random values using the given seed.
 * @param r The record to initialize.
 */
void init_random_record(struct record *r);

/**
 * Returns the number of records in the given file.
 * @param f The file handle.
 * @return The number of records.
 */
long int num_records(FILE *f);

/*
 * Prints given record to stdout.
 * @param r The record.
 */
void print_record(const struct record *r);

/*
 * Prints n records starting at memory location r to stdout.
 * @param r The address of the first record.
 * @param n The number of records to print.
 */
void print_records(const struct record *r, const unsigned int n);

#endif /* __RECORD_H */
