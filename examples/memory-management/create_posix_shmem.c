

/**
 *
 * Shared memory example that uses POSIX calls. 
 * Need to link-in the real time library to compile.
 *
 */
#include	<sys/mman.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"ourhdr.h"

#define	ARRAY_SIZE	 10000
#define	SHM_SIZE	100000
#define	SHM_MODE	(SHM_R | SHM_W)	/* user read/write */

char buffer[ARRAY_SIZE];	

int main(void)
{
	int		shmid;
	char	*shmptr;
	int status;
	
	strcpy(buffer, "Hello World");

	shmid = shm_open("/amit", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (shmid == -1) {
		perror("Error in creating shared memory:");
		exit(1);
	}
	status = ftruncate(shmid, SHM_SIZE);
	if (status == -1) {
		perror("Error in sizing shared memory:");
		exit(1);
	}

	if ((shmptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, shmid, 0)) == (void *)-1)
		perror("mmap error for shmem:");

	
	memcpy(shmptr, buffer, ARRAY_SIZE);
	/*sleep(25);*/

	/*shm_unlink("/amit");*/


	exit(0);
}
