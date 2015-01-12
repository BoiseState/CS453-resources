
#==================================================================
# A Recursive makefile. It invokes the makefiles in each subdirectory
# which in turn invoke makefiles recursively in subdirectories underneath
# those directories.
#==================================================================

all: subdirs

subdirs:
	cd aSimpleClass; make 
	cd lists; make 
	cd simpleExamples; make 
	cd stack; make 
	cd stringTokenizer; make 
	cd mergesort; make

clean:
	cd aSimpleClass; make clean
	cd lists; make clean
	cd simpleExamples; make clean
	cd stack; make clean
	cd stringTokenizer; make clean
	cd mergesort; make clean

