
CC=gcc
CFLAGS= -g   -Wall
#CFLAGS= -O  -Wall
LFLAGS=-lpthread
JFLAGS=

# Recognize files with .class and .java extensions
.SUFFIXES: .class .java
.java.class:
	javac $(JFLAGS) $<

PROGS=mycp stdc-mycp fork-and-wait fork-hello fork-hello-world fork-child-grandchild\
	  fork-and-exec fork-two-children  fork-test simple-shell print-max-no-procs\
	  print-pid print-buffer-sizes skeleton fork-and-exec-xlogo fork-and-exec-chrome\

all: $(PROGS)

mycp: mycp.o
	$(CC) $(CFLAGS) -o mycp mycp.o

stdc-mycp: stdc-mycp.o
	$(CC) $(CFLAGS) -o stdc-mycp stdc-mycp.o

fork-hello: fork-hello.o
	$(CC) $(CFLAGS) -o $@ $< 

fork-hello-world: fork-hello-world.o
	$(CC) $(CFLAGS) -o $@ fork-hello-world.o

fork-child-grandchild: fork-child-grandchild.o
	$(CC) $(CFLAGS) -o $@ fork-child-grandchild.o

fork-and-exec: fork-and-exec.o print-pid
	$(CC) $(CFLAGS) -o $@ fork-and-exec.o

print-pid: print-pid.o
	$(CC) $(CFLAGS) -o $@ print-pid.o

fork-and-wait: fork-and-wait.o
	$(CC) $(CFLAGS) -o $@ fork-and-wait.o

fork-two-children: fork-two-children.o
	$(CC) $(CFLAGS) -o $@ fork-two-children.o

fork-test: fork-test.o
	$(CC) $(CFLAGS) -o $@ fork-test.o

simple-shell: simple-shell.o error.o
	$(CC) $(CFLAGS) -o $@ simple-shell.o error.o

print-max-no-procs: print-max-no-procs.o
	$(CC) $(CFLAGS) -o $@ print-max-no-procs.o

print-buffer-sizes: print-buffer-sizes.o error.o
	$(CC) $(CFLAGS) -o $@ print-buffer-sizes.o error.o

skeleton: skeleton.o
	$(CC) $(CFLAGS) -o $@ $<

fork-and-exec-xlogo: fork-and-exec-xlogo.o
	$(CC) $(CFLAGS) -o $@ $<

fork-and-exec-chrome: fork-and-exec-chrome.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f *.o $(PROGS) a.out core *.class junk log logfile
