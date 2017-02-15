all: test 

compile:
	cd mylib; make

lib: compile
	jar cf mylib.jar mylib/*.class

test: lib
	javac -classpath mylib.jar Test.java

clean:
	cd mylib; make clean
	rm -f *.class mylib.jar
