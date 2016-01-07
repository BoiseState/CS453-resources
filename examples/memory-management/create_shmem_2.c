#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	"ourhdr.h"

#define	ARRAY_SIZE	 10000
#define	MALLOC_SIZE	100000
#define	SHM_SIZE	100000
#define	SHM_MODE	(SHM_R | SHM_W)	/* user read/write */

char buffer[ARRAY_SIZE];	/* uninitialized data = bss */

extern void *_end, *end, *_etext, *etext, *_edata, *edata,
               *__data_start, *__text_start;


int main(void)
{
	int		shmid;
	char	*ptr, *shmptr;
	key_t key;
	
	printf("first address above the text = %p\n", &etext);
	printf("first address above initialized data = %p\n", &edata);
	printf("first address above uninitialized data = %p\n\n", &end);

	printf("buffer[] from %p to %p\n", &buffer[0], &buffer[ARRAY_SIZE]);
	printf("stack around %p\n", &shmid);
	
	strcpy(buffer, "Hello World");

	if ( (ptr = malloc(MALLOC_SIZE)) == NULL)
		err_sys("malloc error");
	printf("malloced from %p to %p\n", ptr, ptr+MALLOC_SIZE);

	key = 1;
	if ( (shmid = shmget(key, SHM_SIZE, SHM_MODE|IPC_CREAT)) < 0)
		err_sys("shmget error");
	if ( (shmptr = shmat(shmid, 0, 0)) == (void *) -1)
		err_sys("shmat error");
	printf("shared memory attached from %p to %p\n", shmptr, shmptr+SHM_SIZE);
	
	memcpy(shmptr, buffer, ARRAY_SIZE);
	sleep(5);

	/*if (shmctl(shmid, IPC_RMID, 0) < 0)*/
		/*err_sys("shmctl error");*/


	exit(0);
}
