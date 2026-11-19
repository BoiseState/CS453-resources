#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
 
#define LAWNIMP
#include "lawnimp.h"
#undef LAWNIMP

using namespace std;

// Plain sleep(3) may be implemented using alarm(2) and SIGALRM.
// Signals have process, not thread, granularity.
// So, we use pthread_cond_timedwait(3).
// Perhaps, usleep(3) or nanosleep(3) would be better.
static void tsleep(int secs) {
  pthread_mutex_t mutex;
  pthread_cond_t cv;
  pthread_mutex_init(&mutex,0);
  pthread_cond_init(&cv,0);

  struct timespec t;
  clock_gettime(CLOCK_REALTIME,&t);
  t.tv_sec+=secs;
  pthread_mutex_lock(&mutex);
  pthread_cond_timedwait(&cv,&mutex,&t);
  pthread_mutex_unlock(&mutex);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cv);
}

static int text() {
  char* v=getenv("DISPLAY");
  return !(v && *v);
}

#define gettid() ((pid_t)syscall(SYS_gettid))
#define WR(X,Y,MSG) printf("(%d,%d) %d %s %s\n",X,Y, gettid(), __func__,MSG)
#define WR0(r) { WR(0,0,""); return r; }

extern LINKAGE void* lawnimp_new(int lawnsize, int molesize) {
  if (Fl::lock()) {
    fprintf(stderr,"Threading not supported.\n");
    exit(1);
  }
  if (text()) WR0(0);
  int size=lawnsize*molesize;
  Fl_Window* w=new Fl_Window(size,size,"Whack-a-Mole");
  w->end();
  w->show();
  return w;
}

extern LINKAGE void lawnimp_run(LawnRep l) {
  if (text()) WR0();
  Fl::run();
}

extern LINKAGE void* lawnimp_mole(MoleRep m) {
  if (text()) {
    WR(m->x,m->y,"creating");
    tsleep(m->vim0);
    WR(m->x,m->y,"created");
    return 0;
  }
  LawnRep l=(LawnRep)m->lawn;
  Fl_Window* w=(Fl_Window*)l->window;
  tsleep(m->vim0);
  Fl::lock();
  w->begin();
  Fl_Box* b=new Fl_Box(m->x,m->y,m->size,m->size);
  b->box(FL_OVAL_BOX);
  b->color(FL_GREEN);
  w->end();
  Fl::redraw();
  Fl::unlock();
  Fl::awake();
  return b;
}

extern LINKAGE void lawnimp_whack(MoleRep m) {
  if (text()) {
    WR(m->x,m->y,"whacking");
    tsleep(m->vim1);
    WR(m->x,m->y,"whacked");
    tsleep(m->vim2);
    WR(m->x,m->y,"expired");
    return;
  }
  LawnRep l=(LawnRep)m->lawn;
  Fl_Window* w=(Fl_Window*)l->window;
  Fl_Box* b=(Fl_Box*)m->box;
  tsleep(m->vim1);
  Fl::lock();
  b->color(FL_RED);
  Fl::redraw();
  Fl::unlock();
  Fl::awake();
  tsleep(m->vim2);
  Fl::lock();
  b->hide();
  Fl::unlock();
  Fl::awake();
  Fl::lock();
  w->remove(b);
  Fl::redraw();
  Fl::unlock();
  Fl::awake();
  delete b;
}

extern LINKAGE void lawnimp_free(void* w) {
  if (text()) WR0();
  Fl_Window* window=(Fl_Window*)w;
  Fl::lock();
  window->hide();
  Fl::unlock();
  Fl::awake();
}
