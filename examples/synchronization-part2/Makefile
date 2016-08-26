
CC=gcc
CFLAGS=-g -Wall 

all: fun daemon_ex1 subdirs 


fun: fun-with-fns.o
	$(CC) $(CFLAGS) -o $@ fun-with-fns.o

dameon_ex1: daemon_ex1.o
	$(CC) $(CFLAGS) -o $@ $<


subdirs:
	cd monitors/java; make
	cd monitors/pthreads; make
	cd signals/; make
	cd pipes/; make
	cd fifos/; make
	cd process-groups/; make

clean:
	/bin/rm -f *.o core a.out fun dup1 dup2 wait1 fifo1 log daemon_ex1
	cd monitors/java/; make clean
	cd monitors/pthreads; make clean
	cd pipes; make clean
	cd fifos; make clean
	cd process-groups/; make clean
