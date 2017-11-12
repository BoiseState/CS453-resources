#!/bin/bash

PROG=$(basename $0)

# Function to print usage message and exit.
print_usage() {
	echo "Usage: $PROG <print|count|info> <file-name>"
	exit 1
}

# Validate number of arguments.
case $# in
0|1)
	print_usage
esac

# Give arguments more readable names.
option=$1
filename=$2

# Validate target file is a file.
if [ ! -f "$filename" ]
then
	echo "$filename is not a file."
	print_usage
fi

# Do what we want to do based on 1st argument.
case "$1" in
        print)
            echo "Printing $filename contents..."
	    cat $filename
            ;;
        count)
            echo "in count..."
            ;;
        info)
            echo "in info..."
            ;;
        *)
	    print_usage
esac


