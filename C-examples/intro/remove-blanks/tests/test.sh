#!/bin/bash

echo "Running tests"
for f in test?
do
	../remove-blanks < $f > $f.out
	echo "processing input " $f
done

echo "Comparing test output with expected output"

for i in 1 2 3 4 5 6 7 8
do
	diff test$i.out out$i
 	echo "---comparing test results $i"
done

echo "All tests PASS!"

