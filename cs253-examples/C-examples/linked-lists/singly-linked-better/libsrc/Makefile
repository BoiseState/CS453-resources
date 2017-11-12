
INSTALL=..
LIB=$(INSTALL)/lib
INCLUDE=$(INSTALL)/include
CC=gcc
CFLAGS=-Wall -g -fPIC -shared -I$(INCLUDE)/ -MMD
LFLAGS=-L$(LIB) -lmylib

LIBOBJS=List.o Node.o

all: libs

libs: libmylib.so  libmylib.a

libmylib.so: $(LIBOBJS)
	$(LD) -shared -fPIC -o $@  $(LIBOBJS)

libmylib.a: $(LIBOBJS)
	$(AR)  rcv $@ $(LIBOBJS)
	ranlib $@

-include *.d

install: libs
	cp  List.h $(INCLUDE)/
	cp  Node.h $(INCLUDE)/
	cp  libmylib.so $(LIB)/libmylib.so
	cp  libmylib.a $(LIB)/libmylib.a

installclean:  clean
	rm -f $(LIB)/libmylib.so
	rm -f $(LIB)/libmylib.a
	rm -f $(INCLUDE)/List.h
	rm -f $(INCLUDE)/Node.h

clean:
	rm -f list *.d *.o a.out core libmylib.a libmylib.so

