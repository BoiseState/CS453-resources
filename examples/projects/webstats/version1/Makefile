
JFLAGS=

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
#
# # This is a rule to convert a file with .java extension
# # into a file with a .class extension. The macro $< just
# # supplies the name of the file (without the extension) 
# # that invoked this rule.
#
.java.class:
	 javac $(JFLAGS) $<


CC=gcc
#CFLAGS= -g   -Wall 
CFLAGS= -O  -Wall  
LIBS=-lpthread
PROGS=webstats  Webstats.class

all: $(PROGS)

webstats: webstats.o error.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ webstats.o error.o

Webstats: Webstats.class

clean:
	/bin/rm -f *.o $(PROGS) Webstats.class
