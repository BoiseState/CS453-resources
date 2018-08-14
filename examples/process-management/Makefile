

CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes
PROGS=deh  deh-static test-bss

all: $(PROGS)

deh: display-elf-headers.o
	$(CC) $(CFLAGS) -o $@ $< 

deh-static: display-elf-headers.o
	$(CC) $(CFLAGS) -static -o $@ $<

test-bss: 	test-bss.o
	$(CC) $(CFLAGS) -o $@ $< 

#deh-static-stripped: display-elf-headers.o
#$(CC) $(CFLAGS) -static --strip-all -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS)
