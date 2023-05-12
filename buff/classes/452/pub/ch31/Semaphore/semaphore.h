#ifndef SEMAPHORE_H
#define SEMAPHORE_H

typedef void *sem_t;

extern void sem_init(sem_t *s, int flags, int value);
extern void sem_wait(sem_t *s);
extern void sem_post(sem_t *s);
extern void sem_destroy(sem_t *s);

#endif
