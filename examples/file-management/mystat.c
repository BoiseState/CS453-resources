
/*
 *
Uses stat system call to get information about the specified file.  You
do not need any access rights to the file to get this information
but  you  need search rights to all directories named in the path
leading to the file.

*/


#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	struct stat statbuf;

	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <filename>\n",argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) <0) {
		perror("Stat error:");
		exit(1);
	}

	printf("device = %ld \n", statbuf.st_dev);
	printf("inode = %lu \n", statbuf.st_ino);
	printf("protection = %o \n", (unsigned) statbuf.st_mode);
	printf("#hard links = %ld \n",  statbuf.st_nlink);
	printf("owner uid = %d (%s) \n",  statbuf.st_uid, 
										getpwuid(statbuf.st_uid)->pw_name );
	printf("owner gid = %d (%s) \n",  statbuf.st_gid, 
										getgrgid(statbuf.st_gid)->gr_name );

	printf("Preferred blocksize for the filesystem = %ld bytes\n",
				statbuf.st_blksize);
	printf("Total number of blocks  = %ld blocks\n",
				statbuf.st_blocks);
	printf("Total size in bytes = %ld bytes\n",
				statbuf.st_size);
	exit(0);
}


