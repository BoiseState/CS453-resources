
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes 
LFLAGS=-lpthread
JFLAGS=

PROGS=mycp threads-dbl-buf-attempt test-random-device

all: $(PROGS) subdirs

mycp: mycp.o
	$(CC) $(CFLAGS) -o $@ $^

threads-dbl-buf-attempt: threads-dbl-buf-attempt.o
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS)

test-random-device: test-random-device.o
	$(CC) $(CFLAGS) -o $@ $^

subdirs:
	cd linux-device-drivers; make

clean:
	/bin/rm -f *.o $(PROGS) a.out core *.class junk log data
	cd linux-device-drivers; make clean
