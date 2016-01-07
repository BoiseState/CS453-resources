#include <semaphore.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

/*
  Shows how to create a semaphore shared across processes!
*/

struct test {
        sem_t mutex1;
        sem_t mutex2;
        int temp;
}test1;

int main(int argc, char **argv)
{
  int fd, i,count=0,nloop=10,zero=0,*ptr;
  struct test *testptr;
  //open a file and map it into memory
  sem_t mutex;
  fd = open("log.txt",O_RDWR|O_CREAT,S_IRWXU);
  write(fd,&zero,sizeof(int));
  ptr = mmap(NULL, sizeof(struct test),PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);
  close(fd);
  memcpy(ptr, &test1, sizeof(test1));
  testptr = (struct test *)ptr;
  // testptr = (struct test *)&test1;
  /* create, initialize semaphore */
  if( sem_init(&(testptr->mutex1),1,1) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
  /* create, initialize semaphore */
  if( sem_init(&(testptr->mutex2),1,0) < 0)
    {
      perror("semaphore initilization");
      exit(0);
    }
  if (fork() == 0) { /* child process*/
    for (i = 0; i < nloop; i++) {
      sem_wait(&(testptr->mutex2));
      printf("child: %d\n", testptr->temp++);
      sem_post(&(testptr->mutex1));
    }
    exit(0);
  }	else {
 	/* back to parent process */
  	for (i = 0; i < nloop; i++) {
    	sem_wait(&testptr->mutex1);
    	printf("parent: %d\n", testptr->temp++);
    	sem_post(&(testptr->mutex2));
  	}
  }
  exit(0);
}

