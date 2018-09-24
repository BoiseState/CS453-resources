
CC=gcc
CFLAGS=-g -Wall -MMD

PROGS=dup dup1 dup2 pipe2 pipe3 pipe4 hello-pipe-1 hello-pipe-2 pipe-talk


all: dup pipes subdirs

dup: dup1 dup2

dup1: dup1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

dup2: dup2.o error.o
	$(CC) $(CFLAGS) -o $@ $^

pipes: pipe2 pipe3 pipe4 hello-pipe-1 hello-pipe-2 pipe-talk


pipe2: pipe2.o error.o
	$(CC) $(CFLAGS) -o $@ $^
	
pipe3: pipe3.o error.o
	$(CC) $(CFLAGS) -o $@ $^

pipe4: pipe4.o error.o
	$(CC) $(CFLAGS) -o $@ $^

hello-pipe-1: hello-pipe-1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

hello-pipe-2: hello-pipe-2.o error.o
	$(CC) $(CFLAGS) -o $@ $^

pipe-talk: pipe-talk.o error.o
	$(CC) $(CFLAGS) -o $@ $^

-include: *.d

subdirs:
	cd anagrams; make

clean:
	/bin/rm -f *.o *.d $(PROGS) 
	cd anagrams; make clean
