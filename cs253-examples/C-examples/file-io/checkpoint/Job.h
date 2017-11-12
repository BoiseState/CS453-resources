

#ifndef __JOB_H
#define __JOB_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXPID_DIGITS 20


typedef struct job  Job;
typedef struct job * JobPtr;

struct job {
    int jobid;
    int infoSize;
    char *info;
};

JobPtr createJob (int, char *);
void freeJob(JobPtr job);

char *toString(JobPtr);

int getJobSize(JobPtr job);
void checkpointJob(JobPtr job, FILE *fout);
JobPtr restoreJob(FILE *fin);


#endif /* __JOB_H */
