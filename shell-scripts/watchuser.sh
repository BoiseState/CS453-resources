#!/bin/bash

case $# in
0) echo 'Usage: ' $prog '<username> <check interval(secs)>'; exit 1;;
esac

name=$1
if test "$2" = ""; then
    interval=60
else
    interval=$2
fi

who | awk '{print $1}' | grep $name >& /dev/null

if test "$?" = "0"; then
    loggedin=true
    echo $name is logged in
else
    loggedin=false
    echo $name not logged in
fi

while true
do
    who | awk '{print $1}' | grep $name >& /dev/null
    if test "$?" = "0"; then
        if test "$loggedin" = "false"; then
        loggedin=true
            echo $name is logged in
        fi
    else
        if test "$loggedin" = "true"; then
            loggedin=false
            echo $name not logged in
        fi
    fi
    sleep $interval
done

