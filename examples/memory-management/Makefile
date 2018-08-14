
CC=gcc
CFLAGS=-g -std=gnu89 -Wall -Wpointer-arith -Wstrict-prototypes
LDFLAGS=-lrt

PROGS= access_shmem create_shmem create_shmem_2 access_shmem_2 create_posix_shmem\
	  access_posix_shmem a.out limits memtest malloc-sbrk memtest sbrk-test 2d_contiguous types\
	  semdemo semrm malloc-and-OS

all: $(PROGS) subdirs

create_shmem: ourhdr.h  create_shmem.o error.o
	$(CC) $(CFLAGS) -o $@ create_shmem.o error.o

access_shmem: ourhdr.h  access_shmem.o error.o
	$(CC) $(CFLAGS) -o $@ access_shmem.o error.o

create_shmem_2: ourhdr.h  create_shmem_2.o error.o
	$(CC) $(CFLAGS) -o $@ create_shmem_2.o error.o

access_shmem_2: ourhdr.h  access_shmem_2.o error.o
	$(CC) $(CFLAGS) -o $@ access_shmem_2.o error.o

create_posix_shmem: ourhdr.h  create_posix_shmem.o error.o
	$(CC) $(CFLAGS) -o $@ create_posix_shmem.o error.o $(LDFLAGS)

access_posix_shmem: ourhdr.h  access_posix_shmem.o error.o
	$(CC) $(CFLAGS) -o $@ access_posix_shmem.o error.o $(LDFLAGS)

semdemo: semdemo.o
	$(CC) $(CFLAGS) -o $@ semdemo.o

semrm: semrm.o
	$(CC) $(CFLAGS) -o $@ semrm.o

types: types.o  
	$(CC) $(CFLAGS) -o $@ $<

2d_contiguous: 2d_contiguous.o
	$(CC) $(CFLAGS) -o $@ $<

a.out: 
	$(CC) -S test.c
	$(CC) -c test.c
	$(CC) $(CFLAGS) test.c 

limits: limits.o
	$(CC) $(CFLAGS) -o $@ $<

memtest: memtest.o
	$(CC) $(CFLAGS) -o $@ $<

malloc-sbrk: malloc-sbrk.o
	$(CC) $(CFLAGS) -o $@ $<

sbrk-test: sbrk-test.o
	$(CC) $(CFLAGS) -o $@ $<

malloc-and-OS: malloc-and-OS.o
	$(CC) $(CFLAGS) -o $@ $<

subdirs:
	cd library-example/; make
	cd library-interposer/; make
	cd simple-malloc/; make

clean:
	/bin/rm -f *.o $(PROGS)
	cd library-example/; make clean
	cd library-interposer/; make clean
	cd simple-malloc/; make clean
