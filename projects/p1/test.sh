#!/bin/bash
# Test script for the endian conversion file
#
# Author: Marissa Schmidt
#         Spring 2014
#-------------------------------------------------------------------------

# Program executable name
EXE=endian

# test input and output files
TESTDIR=./testdata
TESTDATA=$TESTDIR/test.in
EXPECTED=$TESTDIR/test.out

# test result files
RESULT=myresults.out
DIFFRESULT=myresults.diff

# Clear out any results from last run
cat /dev/null > $RESULT

echo "Executing test using input file $TESTDATA."
echo

# Read each line of the test data and execute program
while IFS=' ' read -r field1 field2
do
    ./$EXE "$field1" "$field2" >> $RESULT
done < $TESTDATA;

# Compare the results
diff -w $EXPECTED $RESULT > $DIFFRESULT
if [ $? -ne 0 ] # check result of diff command (0 means they are equal)
then
   echo "Test failed. Check $DIFFRESULT for differences."
   echo
else
   echo "All tests passed!"
   echo
   rm $DIFFRESULT
fi
