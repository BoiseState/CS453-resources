
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

struct record {
    int key;
    double value1;
    double value2;
    double value3;
};

const int MAX_KEY = 1000000;

void generate_file(int n, unsigned int seed, FILE *fout)
{
    int i;
    struct record *next;

    next = (struct record *) malloc(sizeof(struct record));

    for (i=0; i<n; i++) {
        next->key =  i*2;
        next->value1 = rand()/((double)MAX_KEY);
        next->value2 = rand()/((double)MAX_KEY);
        next->value3 = rand()/((double)MAX_KEY);
        fwrite(next, sizeof(struct record), 1, fout);
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

    fout = fopen("data.bin", "w");
    if (!fout) {
        perror("gendata --  opening file data.bin");
		exit(errno);
    }

    generate_file(n ,seed, fout);

    fclose(fout);
    exit(0);
}
