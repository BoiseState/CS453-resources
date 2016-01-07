
DEBUG=
CC=gcc
CFLAGS=-g  -Wall  $(DEBUG)
LFLAGS=-lpthread

OBJS=AlarmClock.o TestAlarm.o

all: TestAlarm 

TestAlarm: AlarmClock.h $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
	

clean:
	/bin/rm -f *.o core a.out $(OBJS) TestAlarm
