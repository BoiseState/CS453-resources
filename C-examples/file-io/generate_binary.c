
/* C-examples/files/generate_binary.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct record {
    int key;
    double value1;
    double value2;
    double value3;
};

const int MAX_KEY = 1000000;
const char *filename = "data.bin";

static void print_record(FILE *fout, struct record *r)
{
    fwrite(r, sizeof(struct record), 1, fout);
}

static struct record *create_random_record()
{
    struct record *r = (struct record *) malloc(sizeof(struct record));

    r->key = rand() % MAX_KEY;
    r->value1 = rand()/((double)MAX_KEY);
    r->value2 = rand()/((double)MAX_KEY);
    r->value3 = rand()/((double)MAX_KEY);

    return r;
}

static void generate_file(int n, unsigned int seed, FILE *fout)
{
    int i;
    struct record *next;

    srand(seed); /* set starting seed for random num. generator */

    for (i = 0; i < n; i++) {
        next = create_random_record();
        print_record(fout, next);
        free(next);
    }
}

int main(int argc, char **argv)
{
    int n;
    unsigned int seed;

    FILE *fout;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n> [<seed>]\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    if (argc == 3) {
        seed = atoi(argv[1]);
    }

    /* Open/create file for writing (starts writing at offset 0). */
    fout = fopen(filename, "w");
    if (!fout) {
        perror(filename);
        exit(errno);
    }

    /* generate and write random entries (plain text) */
    generate_file(n ,seed, fout);

    fclose(fout);

    return 0;
}
