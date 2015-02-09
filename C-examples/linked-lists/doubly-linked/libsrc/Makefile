INSTALL=..
LIB=$(INSTALL)/lib
INCLUDE=$(INSTALL)/include
CC=gcc
CFLAGS=-Wall -g -fPIC -shared -I$(INCLUDE)/
LFLAGS=-L$(LIB) -lmylib


LIBOBJS=List.o Node.o

all: libs


libs: libmylib.so  libmylib.a

libmylib.so: $(LIBOBJS)
	$(LD) -shared -fPIC -o $@  $(LIBOBJS)

libmylib.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@


install: libs
	install --mode=644  List.h $(INCLUDE)/
	install --mode=644  Node.h $(INCLUDE)/
	install --mode=755  libmylib.so $(LIB)/libmylib.so
	install --mode=755  libmylib.a $(LIB)/libmylib.a

installclean:  clean
	rm --force $(LIB)/libmylib.so
	rm --force $(LIB)/libmylib.a
	rm --force $(INCLUDE)/List.h
	rm --force $(INCLUDE)/Node.h

clean:
	rm --force list *.o a.out core libmylib.a libmylib.so

