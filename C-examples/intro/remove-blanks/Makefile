CC = gcc
CFLAGS = -Wall -g

all: remove-blanks

remove-blanks: remove-blanks.o
	$(CC) $(CFLAGS) $^ -o $@

runtests:
	cd tests; ./test.sh

clean:
	rm -f *.o remove-blanks
