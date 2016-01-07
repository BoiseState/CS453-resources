

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

JFLAGS=

all: Consumer.class PC.class Producer.class SharedQueue.class

clean:
	/bin/rm -f *.o *.class
