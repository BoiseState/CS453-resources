#This is your starter Makefile to link the wf.c and WordObject.c
#files to your linked list.
GENERIC_LIST_DIR= #TODO:Point this to your linked list directory
GENERIC_LIST_LIB=$(GENERIC_LIST_DIR)/lib
GENERIC_LIST_INCLUDE=$(GENERIC_LIST_DIR)/include

CC=gcc
IDIR=include
LDIR=lib
CFLAGS=-Wall -g -O -I. -I$(IDIR) -fPIC -MMD 
LFLAGS=-L$(LDIR) -lmylib

PROGS=wf
OBJECTS=wf.o WordObj.o

all: $(PROGS)

wf: libs $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LFLAGS)

-include *.d

libs: generic-list-lib $(LDIR) $(IDIR)

$(LDIR): $(GENERIC_LIST_LIB)
	cp -r $(GENERIC_LIST_LIB) .

$(IDIR): $(GENERIC_LIST_INCLUDE)
	cp -r $(GENERIC_LIST_INCLUDE) .

generic-list-lib:
	cd $(GENERIC_LIST_DIR)/libsrc; make install

libclean:
	cd $(GENERIC_LIST_DIR); make clean
	/bin/rm -fr $(LDIR) $(IDIR)


clean: libclean
	/bin/rm -fr $(PROGS) *.o *.d output/
