
CC=gcc
CFLAGS=-Wall -g  
PROGS=filesize readfile writefile subdirs


all: $(PROGS) 

filesize: filesize.o
	$(CC) $(CFLAGS)  -o $@ $<

readfile: readfile.o
	$(CC) $(CFLAGS)  -o $@ $<

writefile: writefile.o
	$(CC) $(CFLAGS)  -o $@ $<

subdirs:
	cd txt-vs-bin; make
	cd disk_search; make
	cd checkpoint; make
	cd checkpoint-java; make

clean:
	rm --force *.o a.out $(PROGS) data* 
	cd txt-vs-bin; make clean
	cd disk_search; make clean
	cd checkpoint; make clean
	cd checkpoint-java; make clean

