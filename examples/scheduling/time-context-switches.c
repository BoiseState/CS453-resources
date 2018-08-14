
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


#define ITERATIONS 70000000

void printSchedulingPolicy(void)
{
  	int which;
	which = sched_getscheduler(0);
	switch (which) {
	case SCHED_OTHER: 
			printf("default scheduling is being used\n");		
		  	break;
	case SCHED_FIFO:
			printf("fifo scheduling is being used\n");		
		  	break;
	case SCHED_RR:		
			printf("round robin scheduling is being used\n");		
		  	break;
	}		
}


int main(void)
{     

  int sched_setscheduler(pid_t pid, int policy,  const  struct  sched_param *p);
  int sched_getscheduler(pid_t pid);
  int getrusage (int who, struct rusage *usage);
  struct sched_param p;

	struct rusage usage;
	int i;
	int A[1000000];
	
	printSchedulingPolicy();
	p.sched_priority = 1;   
	/*if (sched_setscheduler(0, SCHED_RR, &p) != 0) {*/
	if (sched_setscheduler(0, SCHED_FIFO, &p) != 0) {
		printf("Failed to set the scheduler\n");
	}	   	
	printSchedulingPolicy();


	for (i=0; i<ITERATIONS; i++)
		A[i%999999] = lrand48();
	sched_yield();

	for (i=0; i<ITERATIONS; i++)
		A[i%234567] = lrand48();
	sched_yield();

	for (i=0; i<ITERATIONS; i++)
		A[i%322322] = lrand48();
	sched_yield();

	for (i=0; i<ITERATIONS; i++)
		A[i%454222] = lrand48();
	sched_yield();

	getrusage(RUSAGE_SELF, &usage);
	printf("Number of page faults = %ld\n", usage.ru_majflt);
	printf("Number of voluntary switches = %ld\n", usage.ru_nvcsw);
	printf("Number of involuntary switches = %ld\n", usage.ru_nivcsw);

	exit(0);
}
