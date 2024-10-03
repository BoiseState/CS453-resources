

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

JFLAGS=

all: Dance.class


clean:
	/bin/rm -f *.o *.class log*
