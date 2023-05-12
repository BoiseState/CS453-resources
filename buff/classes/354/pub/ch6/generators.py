#!/usr/bin/python

def seq(beg, end, delta):
    while (delta>=0 and beg<=end) or (delta<0 and beg>=end):
        yield beg
        beg+=delta
        
for i in seq(1,10,2):
    print(i)
