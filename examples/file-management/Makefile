
CC=gcc
CFLAGS=-g -O2 -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes

PROGS=filetype-survey filesize-survey file-io mmap-io mcopy myls mycp seek1 seek2 mystat numproc testfileopen\
	  create-empty-file

all: $(PROGS) d1 pseudo-device.img

FTOBJS=filetype-survey.o error.o pathalloc.o 
$(FTOBJS): ourhdr.h
filetype-survey:	$(FTOBJS)
	$(CC) $(CFLAGS) -o $@  $^  

filesize-survey: filesize-survey.o error.o pathalloc.o
	$(CC) $(CFLAGS) -o $@  $^  

MCOPYOBJS=mcopy.o error.o
$(MCOPYOBJS): ourhdr.h
mcopy: $(MCOPYOBJS)
	$(CC) $(CFLAGS) -o $@ $^

mycp: mycp.o 
	$(CC) $(CFLAGS) -o $@ $^

mmap-io: mmap-io.o error.o 
	$(CC) $(CFLAGS) -o $@ $< error.o

file-io: file-io.o error.o 
	$(CC) $(CFLAGS) -o $@ $< error.o

numproc: numproc.o  error.o
	$(CC) $(CFLAGS) -o $@  $^

myls: myls.o  error.o
	$(CC) $(CFLAGS) -o $@ $^

mystat: mystat.o  error.o
	$(CC) $(CFLAGS) -o $@  $^

seek1: seek1.o
	$(CC) $(CFLAGS) -o $@  $^

seek2: seek2.o
	$(CC) $(CFLAGS) -o $@  $^

create-empty-file: create-empty-file.o
	$(CC) $(CFLAGS) -o $@  $^

testfileopen: testfileopen.o
	$(CC) $(CFLAGS) -o $@  $^

pseudo-device.img: create-empty-file
	echo "Creating empty file of 100MB..."
	./create-empty-file 100

d1:
	mkdir d1; cd d1; mkdir d2; cd d2; ln -s ../../d1 d3
	touch f1; ln -s f1 f2; ln -s f1 f3; ln f1 f4; ln f1 f5
	date > f1
	tar cvf d1.tar d1
	zip -r d1.zip d1
	
clean:
	/bin/rm -f *.o $(PROGS) mem.data.*
	/bin/rm -fr d1/ f? d1.tar d1.zip
	/bin/rm -f pseudo-device.img

