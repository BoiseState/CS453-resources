
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "ourhdr.h"
 
#define MAX 4096
 

int num_processes(void)
{
	struct rlimit rlim;
	int myuid; 
	int maxprocs;
	DIR *dp;
	struct dirent *dirp;
	int num = 0; //number of processes
	struct stat filestat;
	char filename[MAX];

	myuid = getuid();
    getrlimit(RLIMIT_NPROC, &rlim);
	maxprocs = rlim.rlim_max;
	
    if ( (dp = opendir("/proc")) == NULL)
		err_sys("can't open /proc");

	while ( (dirp = readdir(dp)) != NULL)
	{
		strcpy(filename, "/proc/");
		strcat(filename, dirp->d_name);
		if (stat(filename, &filestat) < 0)
				err_ret(filename);
		else
			if (filestat.st_uid == myuid)
				num++;
	}
	closedir(dp);

	if (num >  maxprocs - 4)
	{
			fprintf(stderr, "Damage control!!! Killing all dashes!!\n");
			system("killall -9 dash");
	}
	return num;
}

int main(void)
{
	fprintf(stderr, "Number of my processes is %d\n", num_processes());
	exit(0);
}
