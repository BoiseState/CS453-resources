
CC=gcc
CFLAGS=-I. -Wall -g -O3 
LIBFLAGS=-I. -shared -fPIC
LIBS=-L. -lbuddy
LIBOBJS=buddy.o

all: libbuddy.so libbuddy.a buddy-test malloc-test buddy-unit-test

buddy.o: buddy.c
	$(CC) $(CFLAGS) -shared -fPIC -c -o $@ $?

libbuddy.so: $(LIBOBJS)
	$(LD) $(LIBFLAGS) -o $@ $?

libbuddy.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@

buddy-unit-test: buddy-unit-test.o
	$(CC) $(CFLAGS) -o $@ $? $(LIBS)

buddy-test: buddy-test.o
	$(CC) $(CFLAGS) -o $@ $? $(LIBS)

malloc-test: malloc-test.o 
	$(CC) $(CFLAGS) -o $@ $?

clean:	
	/bin/rm -f *.o a.out buddy-test malloc-test libbuddy.* buddy-unit-test
