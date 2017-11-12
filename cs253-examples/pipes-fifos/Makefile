
CC=gcc
CFLAGS=-Wall -MMD -g

PROGS=pipe-talk hello-pipe hello-pipe-two mypipe

all:  $(PROGS)
	cd fifo; make

pipe-talk: pipe-talk.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-pipe: hello-pipe.o error.o
	$(CC) $(CFLAGS) $^  -o $@

hello-pipe-two: hello-pipe-two.o error.o
	$(CC) $(CFLAGS) $^  -o $@

mypipe: mypipe.o 
	$(CC) $(CFLAGS) $^  -o $@

-include: *.d

clean:
	/bin/rm -f *.o $(PROGS) *.d
	cd fifo; make clean
