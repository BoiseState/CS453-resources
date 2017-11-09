CC=gcc
CFLAGS=-Wall -I. -g -fPIC -shared
LFLAGS=-L$(LIB) -lmylib

all: ring-buffer 

ring-buffer:
	$(CC) $(CFLAGS) -c ring.c
	$(LD) -shared -fPIC -o libring.so ring.o

clean:
	rm -f *.o a.out core libring*
