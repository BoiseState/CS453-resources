
CC=gcc
CFLAGS=-Wall -g -I. -MMD
#CFLAGS=-Wall -O 

OBJS= SearchTest.o ExternalSearch.o Record.o timing.o
PROGS=SearchTest gendata

all: $(PROGS)


gendata: gendata.o
	$(CC) $(CFLAGS)  -o $@ $<

SearchTest: $(OBJS)
	$(CC) $(CFLAGS)  -o $@ $^

-include *.d

clean:
	rm --force *.o *.d *.bin $(OBJS) $(PROGS)
