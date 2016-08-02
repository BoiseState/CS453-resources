CC=gcc
CFLAGS=-g -Wall

PROGS=sig-blocker wake-up pow2-tester timeout catch-null-ptr

all: $(PROGS)

sig-blocker: sig-blocker.o
	$(CC) $(CFLAGS) -o $@ $<

wake-up: wake-up.o
	$(CC) $(CFLAGS) -o $@ $<

catch-null-ptr: catch-null-ptr.o
	$(CC) $(CFLAGS) -o $@ $<

timeout: timeout.o
	$(CC) $(CFLAGS) -o $@ $<

pow2-tester: pow2-tester.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS) a.out
