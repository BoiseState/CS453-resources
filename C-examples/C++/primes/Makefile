
#---------------------------------------------------------------
# Using this Makefile
#
#	To compile your c++ source 
#
#	make 
#
#	To clean up your directory (e.g. before submission)
#
#	make clean
#
#---------------------------------------------------------------

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


CC=g++
# Give all warnings during compilation
CPPFLAGS= -Wall -g  


# To satisfy the rule named all, we must have satisfied the rules
# named compile and doc (given later).
all: primeFactors Primes.class

primeFactors: Primes.o
	$(CC) $(CPPFLAGS) -o primeFactors Primes.o  


clean:
		rm --force  *.o  *.class
		rm --force primeFactors
