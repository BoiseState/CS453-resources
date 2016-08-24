
CC=gcc
CFLAGS=-g -Wall -MMD


all: dup pipes subdirs

dup: dup1 dup2

dup1: dup1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

dup2: dup2.o error.o
	$(CC) $(CFLAGS) -o $@ $^

pipes: p1 p2 p3 p4 hello-pipe hello-pipe-two pipe-talk

p1: pipe1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

p2: pipe2.o error.o
	$(CC) $(CFLAGS) -o $@ $^
	
p3: pipe3.o error.o
	$(CC) $(CFLAGS) -o $@ $^

p4: pipe4.o error.o
	$(CC) $(CFLAGS) -o $@ $^

hello-pipe: hello-pipe.o error.o
	$(CC) $(CFLAGS) -o $@ $^

hello-pipe-two: hello-pipe-two.o error.o
	$(CC) $(CFLAGS) -o $@ $^

pipe-talk: pipe-talk.o error.o
	$(CC) $(CFLAGS) -o $@ $^

-include: *.d

subdirs:
	cd anagrams; make

clean:
	/bin/rm -f *.o p1 p2 p3 p4 dup1 dup2 hello-pipe hello-pipe-two pipe-talk
	cd anagrams; make clean
