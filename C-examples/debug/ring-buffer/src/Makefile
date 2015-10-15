INSTALL=..
LIB=$(INSTALL)/lib
INCLUDE=$(INSTALL)/include
CC=gcc
CFLAGS=-Wall -g -fPIC -shared -I$(INCLUDE)/
LFLAGS=-L$(LIB) -lmylib


LIBOBJS=ring.o

all: libs

libs: libring.so  libring.a

libring.so: $(LIBOBJS)
	$(LD) -shared -fPIC -o $@  $(LIBOBJS)

libring.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@


install: libs
	cp  ring.h $(INCLUDE)/
	cp  libring.so $(LIB)/libring.so
	cp  libring.a $(LIB)/libring.a

clean:  clean
	rm -f $(LIB)/libring.so
	rm -f $(LIB)/libring.a
	rm -f $(INCLUDE)/ring.h
	rm -f *.o a.out core libring.a libring.so
