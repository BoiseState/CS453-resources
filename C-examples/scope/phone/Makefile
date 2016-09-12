# Build all executables.
# 	make all
all: caller1 caller2

# Build caller1 executable.
# Depends on phone.o and caller1.o
# 	make caller1
caller1: phone.o caller1.o
	gcc -Wall phone.o caller1.o -o caller1

# Build caller2 executable.
# Depends on phone.o and caller2.o
# 	make caller2
caller2: phone.o caller2.o
	gcc -Wall phone.o caller2.o -o caller2

# Build phone object file.
# Called when caller1 and/or caller2 are built.
phone.o:
	gcc -Wall -c phone.c

# Build caller1 object file
# Called when caller1 and/or caller2 are built.
caller1.o:
	gcc -Wall -c caller1.c

# Build caller2 object file
# Called when caller1 and/or caller2 are built.
caller2.o:
	gcc -Wall -c caller2.c

# Cleans all object files and executables.
clean:
	rm -rf *.o caller1 caller2
