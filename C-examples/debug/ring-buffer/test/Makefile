#build the grader from the file test.c

CC=gcc
CFLAGS=-Wall -g -I../include 

grader: test-ring-buffer.o
	$(CC) $(CFLAGS) -o $@ $^  -L../lib/ -lring

clean:
	/bin/rm -f *.o grader
