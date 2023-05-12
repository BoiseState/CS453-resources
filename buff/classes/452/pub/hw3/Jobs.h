#ifndef JOBS_H
#define JOBS_H

typedef void *Jobs;

#include "Pipeline.h"

extern Jobs newJobs();
extern void addJobs(Jobs jobs, Pipeline pipeline);
extern int sizeJobs(Jobs jobs);
extern void freeJobs(Jobs jobs);

#endif
