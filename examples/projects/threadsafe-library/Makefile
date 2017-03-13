
CC=gcc

INCLUDE=include/
CFLAGS = -g -O -Wall  -I$(INCLUDE) -I../p0/include/
LIBS=-lpthread -Llib/ -lthreadsafe-mylib -L../p0/lib/ -lmylib 
DEBUG=


all: library pc pc-mq

library:
	cd wrapper-library/; make
	cd wrapper-library/; make install

pc: pc.o  Item.o Item.h
	$(CC) $(CFLAGS) $(DEBUG) -o $@ pc.o Item.o  $(LIBS)

pc-mq: pc-mq.o  Item.o Item.h
	$(CC) $(CFLAGS) $(DEBUG) -o $@ pc-mq.o Item.o  $(LIBS)

clean:
	/bin/rm -f *.o pc pc-mq
	cd wrapper-library/; make installclean
