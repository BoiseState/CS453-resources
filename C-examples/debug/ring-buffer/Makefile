#Builds both the single threaded version
#and the multi threaded version
all: ring ring_mt

#Buils both the single threaded and multi threaded
#test suite 
test: test_suit test_suit_mt

#Build the single threaded version
ring:	
	cd src; make

#Builds the multi threaded version
ring_mt:
	cd src; make mt

#Installs the single threaded version
#NOTE: In a real project this would install
#      into your system lib path
install:
	cd src; make install

#Installs the single threaded version
#NOTE: In a real project this would install
#      into your system lib path
install_mt:
	cd src; make install_mt

#Build the single threaded test suite
test_suit:
	cd test; make

#Build the multi threaded test suite
test_suit_mt:
	cd test; make mt

clean:
	cd src; make clean
	cd test; make clean
