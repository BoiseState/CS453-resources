#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

int daemon_init(void)
{
	pid_t	pid;

	if ( (pid = fork()) < 0)
		return(-1);
	else if (pid != 0)
		exit(0);	/* parent goes bye-bye */

	/* child continues */
	setsid();		/* become session leader */

	chdir("/");		/* change working directory */

	umask(0);		/* clear our file mode creation mask */

	return(0);
}

int main(int argc, char **argv) {
	if (daemon_init() != 0) 
		exit(1);
	/*let sleeping daemons be*/
	for(;;) {sleep(100);}
	exit(0);
}
