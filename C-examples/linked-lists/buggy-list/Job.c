#include "Job.h"

struct job* createJob(int jobid, char *info)
{
    struct job* newJob = (struct job*) malloc (sizeof(struct job*));
    newJob->jobid = jobid;
    newJob->info = (char *) malloc(sizeof(char)*(strlen(info)));
    strcpy(newJob->info, info);
    return newJob;
}

char *toString(struct job* node)
{
    char *temp;
    temp = (char *)malloc(sizeof(char)*strlen(node->info));
    sprintf(temp, "[%d] %s", node->jobid, node->info);
    return temp;
}

void freeJob(struct job* job)
{
	//Don't worry the garbage collector will get it :)
}
