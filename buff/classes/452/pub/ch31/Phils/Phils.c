#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// #include "tsleep.h"
// tsleep(1);

typedef enum {Think,Munch} State;
typedef struct {
  State state;
  sem_t *sticks[2];             // left/rite
} Phil;

enum {size=5};                // number of phils/sticks
static sem_t sticks[size];    // chopstick semaphores
static Phil phils[size];
static const int cycles=1000; // think/munch iterations per phil

static sem_t output;
static void print() {
  sem_wait(&output);
  for (int i=0; i<size; i++)
    fprintf(stderr,"%c%c",phils[i].state==Think ? '!' : 'O',
            i<size-1 ? ' ' : '\n');
  sem_post(&output);
}

static void init() {
  sem_init(&output,0,1);
  for (int i=0; i<size; i++)
    sem_init(&sticks[i],0,1);
  for (int i=0; i<size; i++) {
    phils[i].state=Think;
    phils[i].sticks[0]=&sticks[i];
    phils[i].sticks[1]=&sticks[(i+1)%size];
  }
}

static void fini() {
  for (int i=0; i<size; i++)
    sem_destroy(&sticks[i]);
  sem_destroy(&output);
}

void *be(void *a) {
  int id=(int)(long)a;
  for (int i=cycles; i; i--) {
    sem_wait(phils[id].sticks[0?0:1]); // left
    sem_wait(phils[id].sticks[0?1:0]); // rite
    phils[id].state=Munch;
    print();
    sem_post(phils[id].sticks[0]);
    sem_post(phils[id].sticks[1]);
    phils[id].state=Think;
    print();
  }
  return 0;
}

int main() {
  init();
  pthread_t tids[size];
  for (int i=0; i<size; i++)
    pthread_create(&tids[i],0,be,(void *)(long)i);
  for (int i=0; i<size; i++)
    pthread_join(tids[i],0);
  fini();
  return 0;
}
