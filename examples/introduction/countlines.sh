#!/bin/bash


# You can also use $(cmd) instead of `cmd` for command substitution
# See man page for bash for for more information


total=0
for currfile in `find . -name "*.c" -print`
do
	total=$[total+(`wc -l $currfile| awk '{print $1}'`)]
	echo -n 'total=' $total 
	echo -e -n '\r'
done
echo  'total=' $total 
