
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	gid_t gid, egid;
	uid_t uid, euid;

	uid = getuid();
	printf("I am %s! ", getpwuid(uid)->pw_name);

	euid = geteuid();
	printf("but I am acting effectively as  %s!\n", getpwuid(euid)->pw_name);

	gid = getgid();
	egid = getegid();
	printf("my group is %s and my effective group id is %s\n", 
					getgrgid(gid)->gr_name, getgrgid(egid)->gr_name); 

	exit(0);
}

