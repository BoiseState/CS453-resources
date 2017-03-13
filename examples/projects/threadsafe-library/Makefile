
CC=gcc

INCLUDE=include/
CFLAGS = -g -O -Wall -MMD  -I$(INCLUDE) -I../p0/include/
LIBS=-lpthread -Llib/ -lthreadsafe-mylib -L../p0/lib/ -lmylib 


all: library pc pc-mq

library:
	cd wrapper-library/; make
	cd wrapper-library/; make install

pc: pc.o  Item.o Item.h
	$(CC) $(CFLAGS) -o $@ pc.o Item.o  $(LIBS)

pc-mq: pc-mq.o  Item.o Item.h
	$(CC) $(CFLAGS) -o $@ pc-mq.o Item.o  $(LIBS)

-include *.d

clean:
	/bin/rm -f *.o pc pc-mq *.d
	cd wrapper-library/; make installclean
