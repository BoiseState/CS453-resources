
CC=gcc
INCLUDE=include/
CFLAGS = -g   -Wall  -I$(INCLUDE)
LIBS=-lpthread -Llib/ -lmylib
DEBUG=

pc: pc.o  Item.o Item.h
	$(CC) $(CFLAGS) $(DEBUG) -o $@ pc.o Item.o  $(LIBS)

clean:
	/bin/rm -f *.o pc
