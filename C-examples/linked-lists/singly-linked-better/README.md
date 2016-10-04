
Doubly-linked Lists {#mainpage}
===================

PLEASE COMPLETE THIS README FILE PER NORMAL STANDARDS!

To run the test programs you will need to set the paths to find the library:

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib

Then run the test programs as follows:
First, run a simple smoke test:

testsuite/SimpleTestList

Note that if you cd to testsuite and try to run SimpleTestList there, it will
not find the library because of how we set the LD_LIBRARY_PATH variable above. 
If you want to be able to do that, use the following:

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib:../lib

Next, run the incomplete unit test. You will need to add to it.

testsuite/UnitTestList

Finally, run a larger test that uses the list.

testsuite/RandomTestList

Each program takes command line arguments and will give a help message if run
without the command line arguments.
