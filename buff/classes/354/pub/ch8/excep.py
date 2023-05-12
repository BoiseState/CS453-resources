#!/usr/bin/python
# python excep.py

import sys

class ArgsException(Exception):
    def __init__(self,msg):
        self.msg=msg
    def __str__(self):
        return self.msg

def foo(i):
    if (i<2):
        raise ArgsException("too few args")
    # much more code
    print "foo() done"

try:
    foo(len(sys.argv))
    # much more code
    print "ok"
except ArgsException as e:
    print "not ok:",e
