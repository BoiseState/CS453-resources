
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define SIZE 16385  

int A[SIZE][SIZE];

float report_cpu_time(void);
float report_sys_time(void);
double getMilliseconds(void);
float cputime, systime;
double totaltime;

void run_row_major(void) 
{
	int i, j;

	cputime = report_cpu_time();
    systime = report_sys_time();
	totaltime = getMilliseconds();
    for (i=0; i<SIZE; i++)
             for (j=0; j<SIZE; j++)     
                     A[i][j] = i*j;
    cputime = report_cpu_time() - cputime;
    systime = report_sys_time() - systime;
	totaltime = getMilliseconds() - totaltime;
	printf("\n");
    printf("User time for row major initialization   = %8.0f ms\n", cputime*1000);
    printf("System time for row major initialization = %8.0f ms\n", systime*1000);
    printf("Total time for row major initialization  = %8.0lf ms\n", totaltime);
	printf("\n");

}

void run_column_major(void) 
{
	int i, j;

    cputime = report_cpu_time();
    systime = report_sys_time();
	totaltime = getMilliseconds();
    for (j=0; j<SIZE; j++)
             for (i=0; i<SIZE; i++)     
                     A[i][j] = i*j;
    cputime = report_cpu_time() - cputime;
    systime = report_sys_time() - systime;
	totaltime = getMilliseconds() - totaltime;
	printf("\n");
    printf("User time for column major initialization   = %8.0f ms\n", cputime*1000);
    printf("System time for column major initialization = %8.0f ms\n", systime*1000);
    printf("Total time for column major initialization  = %8.0lf ms\n", totaltime);
	printf("\n");

}

int main(void)
{
    printf(" page size = %ld\n", sysconf(_SC_PAGESIZE));
    run_column_major();
	run_row_major();
	exit(0);
}
