#!/bin/bash
if [ "$1" = "" ];then
  echo "usage: $0 <output file>"
  echo "   output file - the file to save the grades in"
  exit 0;
fi
dest="$1"
#Generate the students assignment
#for this assignment we should have a make file
#which will put the library in a folder called lib
make

#Run the grader. 0 exit status is a pass
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
./grader
if [ $? -eq 0 ];then
	echo "Passed the base grader, running more tests"
else
        echo "P6: FAIL - base grader" >> $dest
	exit 1
fi

#Check to make sure we created the log file
numEntries=5
if [ -e "ring.log" ]; then
    echo "Created a log file"
else
    echo "P6: FAIL - Did not create the log file" >> $dest
    exit 1
fi

len=$(wc -l ring.log | awk '{print $1}')
if [ "$len" -eq "$numEntries" ] 
then
	echo "Found $numEntries entries a log file"
else
    echo "P6: FAIL - Did not create the correct number of entries in the log file" >> $dest
    exit 1
fi

#If we got here we passed
echo "P6: PASS" >> $dest
