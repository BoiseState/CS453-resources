
all: subdirs

subdirs: 
	cd bad; make
	cd almost-generic; make
	cd generic-with-library; make
	cd generic; make

clean:
	cd bad; make clean
	cd almost-generic; make clean
	cd generic-with-library/; make clean
	cd generic; make clean
	
