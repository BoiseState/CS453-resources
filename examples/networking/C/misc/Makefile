
CC=gcc
CFLAGS=-Wall -g  

all: byteorder testrcmd

byteorder:	byteorder.o
	$(CC) $(CFLAGS) byteorder.o -o $@

testrcmd: testrcmd.o
	$(CC) $(CFLAGS) testrcmd.o -o $@

clean:
	/bin/rm -f byteorder *.o core a.out testrcmd
