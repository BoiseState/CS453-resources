
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes -MMD

all: byteorder testrcmd

byteorder:	byteorder.o
	$(CC) $(CFLAGS) byteorder.o -o $@

testrcmd: testrcmd.o
	$(CC) $(CFLAGS) testrcmd.o -o $@

clean:
	/bin/rm -f byteorder *.o core a.out testrcmd
