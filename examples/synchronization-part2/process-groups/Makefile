
CC=gcc
CFLAGS=-g -Wall  -MMD

PROGS=g1 g2 g3 g4 print-gid

all: $(PROGS)

g1: groups1.o error.o
	$(CC) $(CFLAGS) -o $@ $^

g2: groups2.o error.o
	$(CC) $(CFLAGS) -o $@ $^

g3: groups3.o error.o
	$(CC) $(CFLAGS) -o $@ $^

g4: groups4.o error.o
	$(CC) $(CFLAGS) -o $@ $^

print-gid: print-gid.o error.o
	$(CC) $(CFLAGS) -o $@ $^

-include: *.d

clean:
	/bin/rm -f *.o *.d $(PROGS)
