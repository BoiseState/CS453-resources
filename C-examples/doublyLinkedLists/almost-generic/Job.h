#ifndef __JOB_H
#define __JOB_H

#include "common.h"

#define MAXPID_DIGITS 20


typedef struct job Job;
typedef struct job *JobPtr;

struct job {
    int jobid;
    char *info;
};

JobPtr createJob(const int, const char *);
void freeJob(const JobPtr job);

/**
 * @brief Create a string representation of the Job 
 *
 * @param JobPtr the job to stringify
 *
 * @return  the String (Caller responsible for freeing memory)
 */
char *toString(const JobPtr);


#endif /* __JOB_H */
