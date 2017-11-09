
/* C-examples/files/filesize.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv)
{
    long int size;
    FILE *fin;

    if (argc !=2 ) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fin = fopen(argv[1], "r");
    if (!fin) {
        perror("filesize:");
        exit(errno);
    }
    fseek(fin, 0, SEEK_END);
    size = ftell(fin);
    printf("Size of the file %s = %lf MB [%ld bytes]\n", argv[1],
           (double) size/(1024*1024), size);

    // Alternate method. Not fully portable. POSIX standard, not C standard.
    /*struct stat st;
    stat(argv[1], &st);
    size = st.st_size;
    printf("Size of the file %s = %lf MB\n", argv[1],  (double) size/(1024*1024));
    */
    exit(0);
}
