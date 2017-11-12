#include "Job.h"


struct job * createJob(int jobid, char *info)
{
    struct job * newJob = (struct job *) malloc (sizeof(Job));
    newJob->jobid = jobid;
    newJob->info = (char *) malloc(sizeof(char)*(strlen(info)+1));
    strcpy(newJob->info, info);
    newJob->infoSize = strlen(info)+1;
    return newJob;
}

char *toString(struct job * job)
{
    char *temp;
    temp = (char *)malloc(sizeof(char)*(job->infoSize)+MAXPID_DIGITS+4);
    sprintf(temp, "[%d] %s", job->jobid, job->info);
    return temp;
}

void freeJob(struct job * job)
{

}

int getJobSize(struct job * job)
{
    int size = 0;
    size = sizeof(int) + sizeof(int) +  job->infoSize;
    return size;
}


/*
Function name: checkpointJob
Description: WARNING! Writes a checkpoint for a Job structure to  an output
            stream without any checks. The idea is that some higher level
            class (like List or Node) would call this function after having
            checked for the file output stream to be set properly. We also
            don't check for no space left to write the file...
    Input: job  ---> a pointer to a Job structure that needs to be checkpointed
           fout ---> output file stream

    Output: none
    Side Effects: writes to  a specified output stream


*/
void checkpointJob(struct job *job, FILE *fout)
{
    fwrite(&(job->jobid), sizeof(int), 1, fout);
    fwrite(&(job->infoSize), sizeof(int), 1, fout);
    fwrite(job->info, job->infoSize, 1, fout);
}

/*
    a different way of checkpointing...

void checkpointJob(struct job * job, FILE *fout)
{
    int size;
    void *buffer;

    size = getJobSize(job);
    buffer = (void *) malloc(sizeof(char)*size);
    memcpy(buffer, &(job->jobid), sizeof(int));
    memcpy(buffer+sizeof(int), &(job->infoSize), sizeof(int));
    memcpy(buffer+sizeof(int)+sizeof(int), job->info, job->infoSize);
    fwrite(buffer, size, 1, fout);
    free(buffer);
}
*/

/*
Function name: restoreJob
Description: WARNING! Reads from a binary input stream to rsrtore a Job
            structure. The idea is that some higher level
            class (like List or Node) would call this function after having
            checked for the file input stream to be set properly. We
            don't check for EOF or other errors at this level.

    Input: fin ---> binary input stream

    Output:   ---> a pointer to the restored Job structure
    Side Effects: None outside of the Job structure
*/
struct job *restoreJob(FILE *fin)
{
    int jobid;
    int infoSize;
    struct job * job;

    fread(&jobid, sizeof(int), 1, fin);
    fread(&infoSize, sizeof(int), 1, fin);
    job = createJob(jobid, "");
    job->info = (char *) malloc(sizeof(char)*infoSize);
    fread(job->info, infoSize, 1, fin);
    return job;
}
