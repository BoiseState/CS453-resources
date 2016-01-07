#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	"ourhdr.h"

#define	ARRAY_SIZE	 10000
#define	SHM_SIZE	100000
#define	SHM_MODE	(SHM_R | SHM_W)	/* user read/write */

char buffer[ARRAY_SIZE];	

int main(void)
{
	int		shmid;
	char	*shmptr;
	key_t key;
	
	strcpy(buffer, "Hello World");

	key = 1;
	if ( (shmid = shmget(key, SHM_SIZE, SHM_MODE|IPC_CREAT)) < 0)
		err_sys("shmget error");
	if ( (shmptr = shmat(shmid, 0, 0)) == (void *) -1)
		err_sys("shmat error");
	
	memcpy(shmptr, buffer, ARRAY_SIZE);
	/*sleep(25);*/

	/*if (shmctl(shmid, IPC_RMID, 0) < 0)*/
		/*err_sys("shmctl error");*/


	exit(0);
}
