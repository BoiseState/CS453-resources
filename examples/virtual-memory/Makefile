
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes -MMD

all: pft  exhaust-vm

pft: page-fault-test.o timing.o
	$(CC) $(CPPFLAGS) -o $@ page-fault-test.o timing.o

exhaust-vm: exhaust-vm.o
	$(CC) $(CPPFLAGS) -o $@ exhaust-vm.o 

clean:
	/bin/rm -f *.o core pft exhaust-vm a.out
