

#include <stdio.h>
#include <sys/times.h> /* for times system call */
#include <sys/time.h>  /* for gettimeofday system call */
#include <unistd.h>


/*
---------------------------------------------------------------------------
clock_t times(struct tms *buffer);

times() fills the structure pointed to by buffer with
time-accounting information.  The structure defined in
<sys/times.h> is as follows:

struct tms {
    clock_t tms_utime;       user time
    clock_t tms_stime;       system time
    clock_t tms_cutime;      user time, children
    clock_t tms_cstime;      system time, children

The time is given in units of 1/CLK_TCK seconds where the
value of CLK_TCK can be determined using the sysconf() function
with the agrgument _SC_CLK_TCK.
---------------------------------------------------------------------------
*/


float report_cpu_time(void)
{
    struct tms buffer;
    float cputime;

    times(&buffer);
    cputime = (buffer.tms_utime)/ (float) sysconf(_SC_CLK_TCK);
    return (cputime);
}


float report_sys_time(void)
{
    struct tms buffer;
    float systime;

    times(&buffer);
    systime = (buffer.tms_stime)/ (float) sysconf(_SC_CLK_TCK);
    return (systime);
}

double getMilliSeconds(void)
{
    struct timeval now;
    gettimeofday(&now, (struct timezone *)0);
    return (double) now.tv_sec*1000.0 + now.tv_usec/1000.0;
}

