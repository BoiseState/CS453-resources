
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes

all: subdirs 


subdirs:
	cd monitors/java; make
	cd monitors/pthreads; make

clean:
	/bin/rm -f *.o core a.out 
	cd monitors/java/; make clean
	cd monitors/pthreads; make clean
