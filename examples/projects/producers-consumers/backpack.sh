#!/bin/bash
echo "Building project...."
make

if [ ! -f pc ]; then
	echo "pc executable not found!"
fi

echo
echo "Running tests...this will take a few minutes"
echo

test-pc.sh 2>&1 | grep "FAILED"

if test $? -eq 1
then
	echo "Backpack: all tests passed!"
else
	echo "Backpack: some tests failed!!!!"
fi

echo
make clean 2>&1 /dev/null
echo


