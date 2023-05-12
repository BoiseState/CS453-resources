#include "Jobs.h"
#include "deq.h"
#include "error.h"

extern Jobs newJobs() {
  return deq_new();
}

extern void addJobs(Jobs jobs, Pipeline pipeline) {
  deq_tail_put(jobs,pipeline);
}

extern int sizeJobs(Jobs jobs) {
  return deq_len(jobs);
}

extern void freeJobs(Jobs jobs) {
  deq_del(jobs,freePipeline);
}
