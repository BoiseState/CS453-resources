#!/bin/bash

check_usage() {
    case $# in
    0) echo 'Usage: ' $prog '<username> <check interval(secs)>'; exit 1;;
    esac
}

check_user() {
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
}

check_usage $*

name=$1
if test "$2" = ""; then
    interval=60
else
    interval=$2
fi

loggedin=false
check_user $name

while true
do
    check_user $name 
    sleep $interval
done
