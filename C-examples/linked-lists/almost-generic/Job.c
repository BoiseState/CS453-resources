#include "Job.h"


JobPtr createJob(const int jobid, const char *info)
{
    JobPtr newJob = (JobPtr) malloc(sizeof(Job));
    newJob->jobid = jobid;
    newJob->info = (char *) malloc(sizeof(char) * (strlen(info) + 1));
    strncpy(newJob->info, info, strlen(info) + 1);
    return newJob;
}

char *toString(const JobPtr node)
{
    int maxLength = strlen(node->info) + 1 + MAXPID_DIGITS + 4;
    char *temp = (char *) malloc(sizeof(char) * maxLength);
    snprintf(temp, maxLength, "[%d] %s", node->jobid, node->info);
    return temp;
}

void freeJob(const JobPtr job)
{
    if (job == NULL)
	    return;
    free(job->info);
    free(job);
}
