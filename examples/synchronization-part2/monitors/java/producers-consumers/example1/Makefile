

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

JFLAGS=

CC=gcc
#CFLAGS=-I. -g   -Wall
CFLAGS=-I. -O  -Wall
LDFLAGS=-lpthread
OBJS=semaphore.o

all: Consumer.class PC.class Producer.class SharedQueue.class

clean:
	/bin/rm -f *.o *.class log*
