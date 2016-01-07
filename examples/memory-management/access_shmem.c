#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	"ourhdr.h"

#define	ARRAY_SIZE	 10000
#define	SHM_SIZE	100000
#define	SHM_MODE	(SHM_R | SHM_W)	/* user read/write */

char	buffer[ARRAY_SIZE];	/* uninitialized data = bss */


int main(void)
{
	int		shmid;
	char	*shmptr;
	key_t key;
	
	key = 1;
	if ( (shmid = shmget(key, SHM_SIZE, SHM_MODE)) < 0)
		err_sys("shmget error");
	if ( (shmptr = shmat(shmid, 0, 0)) == (void *) -1)
		err_sys("shmat error");

	memcpy(buffer, shmptr, ARRAY_SIZE);
	printf("From shared memory: %s\n", buffer);

	sleep(64);
	if (shmdt(shmptr) < 0)
		err_sys("shmdt error");

	exit(0);
}
