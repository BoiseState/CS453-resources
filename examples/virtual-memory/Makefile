
CC=gcc
CPP=g++
CPPFLAGS= -O -Wall

all: pft  exhaust-vm

pft: page-fault-test.o timing.o
	$(CC) $(CPPFLAGS) -o $@ page-fault-test.o timing.o

exhaust-vm: exhaust-vm.o
	$(CPP) $(CPPFLAGS) -o $@ exhaust-vm.o 

clean:
	/bin/rm -f *.o core pft exhaust-vm a.out
