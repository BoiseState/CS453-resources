#include <windows.h>
#include <stdio.h>

#define BUF_SIZE 65536
#define DEBUG 1

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    size_t in, out;
    char buf[BUF_SIZE];
    int bufsize;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        ExitProcess(1);
    }

    bufsize = atoi(argv[1]);
    if (bufsize > BUF_SIZE) {
        fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], BUF_SIZE);
        ExitProcess(1);
    }

    src = fopen(argv[2], "r");
    if (NULL == src)
        ExitProcess(2);

    dst = fopen(argv[3], "w");
    if (dst < 0)
        ExitProcess(3);

    while (1) {
        in = fread(
                 buf,           // Storage location for data
                 1,             // Item size in bytes
                 bufsize,       // Maximum number of items to be read
                 src            // Pointer to FILE structure
             );
        if (0 == in)
            break;
#ifdef DEBUG
        printf("read %d character\n", in);
#endif

        out = fwrite(
                  buf,      // Pointer to data to be written
                  1,            // Item size in bytes
                  in,       // Maximum number of items to be written
                  dst       // Pointer to FILE structure
              );
        if (0 == out)
            break;
#ifdef DEBUG
        printf("wrote %d character\n", out);
#endif
    }

    fclose(src);
    fclose(dst);
    ExitProcess(0);
}