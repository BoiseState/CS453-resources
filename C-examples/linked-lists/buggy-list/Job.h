#ifndef __JOB_H
#define __JOB_H

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define MAXPID_DIGITS 20

struct job {
    int jobid;
    char *info;
};

struct job* createJob (int, char *);
void freeJob(struct job* job);
char *toString(struct job*);

#endif /* __JOB_H */
