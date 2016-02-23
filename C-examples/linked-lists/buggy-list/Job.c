#include "Job.h"


JobPtr createJob(int jobid, char *info)
{
    JobPtr newJob = (JobPtr) malloc (sizeof(Job));
    newJob->jobid = jobid;
    newJob->info = (char *) malloc(sizeof(char)*(strlen(info)+1));
    strcpy(newJob->info, info);
    return newJob;
}

char *toString(JobPtr node)
{
    char *temp;
    temp = (char *)malloc(sizeof(char)*strlen(node->info)+1+MAXPID_DIGITS+4);
    sprintf(temp, "[%d] %s", node->jobid, node->info);
    return temp;
}

void freeJob(JobPtr job)
{

}
