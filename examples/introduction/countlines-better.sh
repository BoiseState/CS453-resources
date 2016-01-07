#!/bin/bash

folder=$1
DEBUG=true

total=0
totalj=0
numfiles=0
for folder in $*
do
	for currfile in `find $folder -name "*.[c|h|cc]" -print`
	do
		total=$[total+(`wc -l $currfile| awk '{print $1}'`)]
		numfiles=$[numfiles+1]
		if test "$DEBUG" = "true"  
		then 
				echo -n 'total=' $total
				echo -n -e '\r'
		fi
	done
	echo "Total number of lines in C/C++ programs = "$total

	for currfile in `find $folder -name "*.java" -print`
	do
		totalj=$[totalj+(`wc -l $currfile| awk '{print $1}'`)]
		numfiles=$[numfiles+1]
		if test "$DEBUG" = "true"  
		then 
				echo -n 'total=' $total
				echo -n -e '\r'
		fi
	done
done

echo "Total number of lines in Java programs = "$totalj
echo "Total number of lines in C/C++ programs = "$total
echo "Total number of lines in C/C++/Java programs = " $[total+totalj]
echo "Total number of matching files = " $numfiles

# vim: set ts=4: 
