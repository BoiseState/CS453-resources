#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	"ourhdr.h"

#define	ARRAY_SIZE	 10000
#define	SHM_SIZE	100000
#define	SHM_MODE	(SHM_R | SHM_W)	/* user read/write */

char	buffer[ARRAY_SIZE];	/* uninitialized data = bss */

extern void *_end, *end, *_etext, *etext, *_edata, *edata,
               *__data_start, *__text_start;


int main(void)
{
	int		shmid;
	char	*shmptr;
	key_t key;
	
	printf("first address above the text = %p\n",&etext);
	printf("first address above initialized data = %p\n",&edata);
	printf("first address above uninitialized data = %p\n\n",&end);

	printf("buffer[] from %p to %p\n", &buffer[0], &buffer[ARRAY_SIZE]);
	printf("stack around %p\n", &shmid);

	key = 1;
	if ( (shmid = shmget(key, SHM_SIZE, SHM_MODE)) < 0)
		err_sys("shmget error");
	if ( (shmptr = shmat(shmid, 0, 0)) == (void *) -1)
		err_sys("shmat error");
	printf("shared memory attached from %p to %p\n", shmptr, shmptr+SHM_SIZE);

	memcpy(buffer, shmptr, ARRAY_SIZE);
	printf("From shared memory: %s\n", buffer);

	if (shmdt(shmptr) < 0)
		err_sys("shmdt error");

	exit(0);
}
