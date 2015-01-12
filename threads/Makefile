
CC=gcc
CFLAGS= -g   -Wall
#CFLAGS= -O  -Wall
LFLAGS=-lpthread


PROGS=thread-hello-world thread-better-hello-world thread-cp thread-test seq-sum thread-sum\
	  thread-ex thread-ids bad-bank-balance safe-bank-balance random_r

all: $(PROGS) subdirs


subdirs:
	cd java; make

thread-hello-world: thread-hello-world.o
	$(CC) $(CFLAGS) -o $@ thread-hello-world.o $(LFLAGS)

thread-sum: thread-sum.o timing.o
	$(CC) $(CFLAGS) -o $@ thread-sum.o timing.o $(LFLAGS)

seq-sum: seq-sum.o timing.o
	$(CC) $(CFLAGS) -o $@ seq-sum.o timing.o $(LFLAGS)

thread-better-hello-world: thread-better-hello-world.o
	$(CC) $(CFLAGS) -o $@ thread-better-hello-world.o $(LFLAGS)

thread-cp: thread-cp.o
	$(CC) $(CFLAGS) -o $@ thread-cp.o $(LFLAGS)

thread-test: thread-test.o
	$(CC) $(CFLAGS) -o $@ thread-test.o $(LFLAGS)

thread-ex: thread-ex.o
	$(CC) $(CFLAGS) -o $@ thread-ex.o $(LFLAGS)

thread-ids: thread-ids.o
	$(CC) $(CFLAGS) -o $@ thread-ids.o $(LFLAGS)

bad-bank-balance: bad-bank-balance.o
	$(CC) $(CFLAGS) -o $@ bad-bank-balance.o $(LFLAGS)

safe-bank-balance: safe-bank-balance.o
	$(CC) $(CFLAGS) -o $@ safe-bank-balance.o $(LFLAGS)

random_r: random_r.o
	$(CC) $(CFLAGS) -o $@ random_r.o $(LFLAGS)

clean:
	/bin/rm -f *.o $(PROGS) a.out core *.class junk log logfile
	cd java; make clean
