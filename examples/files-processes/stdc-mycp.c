#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 65536
/*#define DEBUG 1*/

#define SUCCESS 0
#define INCORRECT_CMDLINE_ARGS 1
#define BUFFER_SIZE_TOO_LARGE 2
#define FILE_OPEN_FOR_READ_FAILED 3
#define FILE_OPEN_FOR_WRITE_FAILED 4

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    size_t in, out;
    char buf[BUF_SIZE];
    int bufsize;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        return (INCORRECT_CMDLINE_ARGS);
    }

    bufsize = atoi(argv[1]);
    if (bufsize > BUF_SIZE) {
        fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], BUF_SIZE);
        return (BUFFER_SIZE_TOO_LARGE);
    }

    src = fopen(argv[2], "r");
    if (src == NULL)
        return (FILE_OPEN_FOR_READ_FAILED);
//  setbuf(src, NULL);     // disables internal buffer stream

    dst = fopen(argv[3], "w");
    if (dst < 0)
        return (FILE_OPEN_FOR_WRITE_FAILED);
//  setbuf(dst, NULL);     // disables internal buffer stream

    while (1) {
        in = fread(
                 buf,           // Storage location for data
                 1,             // Item size in bytes
                 bufsize,       // Maximum number of items to be read
                 src            // Pointer to FILE structure
             );
        if (in == 0)
            break;
#ifdef DEBUG
        printf("read %ld character\n", in);
#endif

        out = fwrite(
                  buf,      // Pointer to data to be written
                  1,        // Item size in bytes
                  in,       // Maximum number of items to be written
                  dst       // Pointer to FILE structure
              );
        if (out == 0)
            break;
#ifdef DEBUG
        printf("wrote %ld character\n", out);
#endif
    }

    fclose(src);
    fclose(dst);
    return (SUCCESS);
}
