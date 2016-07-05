CC=gcc
CFLAGS=-Wall -g

#This executes the command "ls" and then assigns
#the value to the variable DIR
DIRS=$(shell ls -d */)

#This is the first rule in the file so it is the
#rule that make will execute if you do not give
#it an explicit target
all: build

#The default build command.
build:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir) && ) true

clean:
	@$(foreach dir, $(DIRS), $(MAKE) -C $(dir) clean && ) true
