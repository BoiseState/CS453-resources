#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "record.h"

const int MAX_KEY = 1000000;

void init_random_record(struct record *r)
{
    /* Make sure all data is set to 0's. Structs sizes are aligned to machine
     * words, so initializing all members doesn't necessarily initialize all
     * bytes it occupies. Causes valgrind error with fwrite if we don't do
     * this. */
    memset(r, 0, sizeof(struct record));

    r->key = random() % MAX_KEY;
    r->value1 = random()/((double)MAX_KEY);
    r->value2 = random()/((double)MAX_KEY);
    r->value3 = random()/((double)MAX_KEY);
}

void generate_record_file(const int unsigned n, const char *filename, void (*write_record)(struct record *, FILE *fout))
{
    FILE *fout;
    int i;
    struct record r;

    fout = fopen(filename, "w");
    if (!fout) {
        perror(filename);
        exit(errno); /* errno will get set by the OS */
    }

    for (i = 0; i < n; i++) {
        init_random_record(&r);
        write_record(&r, fout);
    }

    fclose(fout);
}

long int num_records(FILE *file)
{
    /* This is one way to do it...*/
    long int count = 0;

    fseek(file, 0, SEEK_END);
    count = ftell(file);
    rewind(file);

    if(count > 0) {
        count = count/sizeof(struct record);
    }

    return count;
}

void print_record(const struct record *r)
{
    printf("%d %lf %lf %lf\n", r->key, r->value1, r->value2, r->value3);
}

void print_records(const struct record *r, const unsigned int n)
{
    int i;
    for (i = 0; i < n; i++) {
        print_record(&r[i]);
    }
}

