CC=gcc
CFLAGS=-g -Wall

PROGS=sig-handler wake-up pow2Tester timeout

all: $(PROGS)

sig-handler: sig-handler.o
	$(CC) $(CFLAGS) -o $@ $<

wake-up: wake-up.o
	$(CC) $(CFLAGS) -o $@ $<

timeout: timeout.o
	$(CC) $(CFLAGS) -o $@ $<

pow2Tester: pow2Tester.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS) a.out
