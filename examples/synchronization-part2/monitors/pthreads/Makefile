
# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

JFLAGS=

DEBUG=
CC=gcc
CFLAGS=-g   -Wall  $(DEBUG)
LFLAGS=-lpthread

all: thread-signals subdirs

thread-signals: thread-signals.o error.o
	$(CC) $(CFLAGS) -o $@ thread-signals.o $(LFLAGS)

subdirs:
	cd account; make
	cd producers-consumers/; make
	cd alarm-clock/; make


clean:
	/bin/rm -f *.o core a.out thread-signals 
	cd account; make clean
	cd producers-consumers/; make clean
	cd alarm-clock/; make clean
