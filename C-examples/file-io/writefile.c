#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
    if(argc != 2) {
        printf("Usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    FILE *fout = fopen(argv[1], "w");
    if(!fout) {
        perror(argv[1]);
        exit(errno);
    }

	int i;
    for(i = 0; i < 10; i++) {
       fprintf(fout, "message %d\n", i);
    }

    fclose(fout);
    return 0;
}
