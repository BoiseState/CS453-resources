INSTALL=.
LIB=$(INSTALL)/lib
INCLUDE=$(INSTALL)/include

#Builds the single threaded version
#We will extend this rule in the next homework
#to build both the single and multi-threaded version
all: test-code dox

#Build the single threaded version
#and then copy over the build artifacts
ring:
	cd libsrc; make
	mv libsrc/libring.so $(LIB)
	cp libsrc/ring.h $(INCLUDE)

#First build all the dependencies then build
#the test code and copy the tester to the top level
test-code: ring
	cd test; make
	mv test/grader .

dox:
	doxygen doxygen-config >& doxygen.log

clean:
	rm -f lib/*.so
	rm -f include/*.h
	rm -f grader
	rm -fr docs/ doxygen.log
	cd libsrc; make clean
	cd test; make clean
