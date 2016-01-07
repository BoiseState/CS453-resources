/*
 *  footest.c
 *
 *  Copyright (C) 1997  Fernando Matia
 */

/*
 *  Example for /dev/foo testing
 */

#include <stdio.h>           /* For printf(), scanf(), etc             */
#include <sys/types.h>       /* For open() y read()                    */
#include <unistd.h>          /* For read() y close()                   */
#include <sys/stat.h>        /* For open()                             */
#include <fcntl.h>           /* For open()                             */
#include <sys/ioctl.h>       /* For ioctl()                            */
#include <linux/foo.h>       /* foo_struct Structure and y definitions */

int fd;                      /* File descriptor for the driver         */
long output;                 /* Value which returns the driver         */
int input;                   /* Input value to the driver              */
int factor;                  /* Multiplication factor                  */

void main()
{
    if( (fd = open("/dev/foo", O_RDWR, 0)) < 0) {
        printf("Error opening foo\n");
        exit(1);
        }

    if( read(fd, (char *) &output, sizeof(long)) < 0) {
        printf("Error reading from foo\n");
        close(fd);
        exit(1);
        }
    printf("Output = %d\n", output);

    input = 70;
    if( write(fd, (char *) &input, sizeof(int)) < 0) {
        printf("Error writing to foo\n");
        close(fd);
        exit(1);
        }

    if( read(fd, (char *) &output, sizeof(long)) < 0) {
        printf("Error reading from foo\n");
        close(fd);
        exit(1);
        }
    printf("Output = %d\n", output);

    factor = 20;
    if( ioctl(fd, FOO_SET, (char *) &factor) ) {
        printf("Error using ioctl\n");
        close(fd);
        exit(0);
        }

    if( read(fd, (char *) &output, sizeof(long)) < 0) {
        printf("Error reading from foo\n");
        close(fd);
        exit(1);
        }
    printf("Output = %d\n", output);

    if( ioctl(fd, FOO_RESET) ) {
        printf("Error using ioctl\n");
        close(fd);
        exit(0);
        }

    if( read(fd, (char *) &output, sizeof(long)) < 0) {
        printf("Error reading from foo\n");
        close(fd);
        exit(1);
        }
    printf("Output = %d\n", output);

    if( ioctl(fd, FOO_GET, &input) ) {
        printf("Error using ioctl\n");
        close(fd);
        exit(0);
        }
    printf("Input = %d\n", input);

    if( close(fd) ) {
        printf("Error closing foo\n");
        exit(1);
        }

    exit(0);
}
