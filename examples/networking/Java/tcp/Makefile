
#---------------------------------------------------------------
# Using this Makefile
#
#   To compile your java source (and generate documentation)
#
#   make
#
#   To clean up your directory (e.g. before submission)
#
#   make clean
#
#---------------------------------------------------------------

JFLAGS=

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java

# This is a rule to convert a file with .java extension
# into a file with a .class extension. The macro $< just
# supplies the name of the file (without the extension)
# that invoked this rule.

.java.class:
	javac $(JFLAGS) $<


all: subdirs FingerAtHost.class DateAtHost.class 

subdirs:
	cd object-server/; make
	cd socket-options/; make
	cd single-threaded/; make
	cd multi-threaded/; make

clean:
	cd object-server/; make clean
	cd socket-options/; make clean
	cd single-threaded/; make clean
	cd multi-threaded/; make clean
	/bin/rm -f *.class
