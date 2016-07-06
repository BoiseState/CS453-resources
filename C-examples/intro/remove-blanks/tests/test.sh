#!/bin/bash

for f in test?
do
	../remove-blanks < $f > $f.out
	echo "processing input " $f
done

