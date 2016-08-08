
CC=gcc
CFLAGS= -g   -Wall
#CFLAGS= -O  -Wall
LFLAGS=-lpthread -lm


PROGS=thread-hello-world thread-better-hello-world thread-cp thread-test seq-sum thread-sum\
	  thread-ex thread-ids bad-bank-balance safe-bank-balance safe-bank-balance-starvation\
	  random_r thread-big-calc

all: $(PROGS) subdirs


subdirs:
	cd java; make
	cd account; make

thread-hello-world: thread-hello-world.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-sum: thread-sum.o timing.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

seq-sum: seq-sum.o timing.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-better-hello-world: thread-better-hello-world.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-cp: thread-cp.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-test: thread-test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-ex: thread-ex.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-ids: thread-ids.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

thread-big-calc: thread-big-calc.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

bad-bank-balance: bad-bank-balance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

safe-bank-balance: safe-bank-balance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

safe-bank-balance-starvation: safe-bank-balance-starvation.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

random_r: random_r.o
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean:
	/bin/rm -f *.o $(PROGS) a.out core *.class junk log logfile
	cd java; make clean
	cd account; make clean
