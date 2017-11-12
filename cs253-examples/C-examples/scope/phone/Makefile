# Build all executables.
# 	make all
all: caller1 caller2

# Build caller1 executable. Depends on caller1.o and phone.o 
# 	make caller1
caller1: caller1.o phone.o 
	gcc -Wall caller1.o phone.o -o caller1

# Build caller2 executable. Depends on caller2.o and phone.o 
# 	make caller2
caller2: caller2.o phone.o 
	gcc -Wall caller2.o phone.o -o caller2

# Build phone object file. Called when caller1 and/or caller2 are built.
phone.o: phone.c phone.h
	gcc -Wall -c phone.c

# Build caller1 object file. Called when caller1 is built.
caller1.o: caller1.c caller.h
	gcc -Wall -c caller1.c

# Build caller2 object file. Called when caller2 is built.
caller2.o: caller2.c caller.h
	gcc -Wall -c caller2.c 

# Cleans all object files and executables.
clean:
	rm -rf *.o caller1 caller2
