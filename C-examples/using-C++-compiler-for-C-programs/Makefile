
CC=g++
CFLAGS=-Wall -g  


all: pointers arrays 

pointers: pointers.o
	$(CC) $(CFLAGS) -o $@ $<

arrays: arrays.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm --force arrays pointers *.o core a.out
