#!/bin/sh

while true
do
	./thread-id | grep "\-1"
	usleep 10000
done
