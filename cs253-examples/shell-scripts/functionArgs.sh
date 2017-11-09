#!/bin/bash

echoargs ()
{
    echo '=== function args'
    for f in $*
    do
        echo $f
    done
} 

echo --- before function is called
for f in $*
do
    echo $f
done
    
echoargs a b c

echo --- after function returns
for f in $*
do
    echo $f
done
