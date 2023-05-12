#!/bin/bash

prg=${0##*/}
tmp=/tmp/$prg.$$

trap "rm -f $tmp $tmp.*" EXIT

> $tmp
> $tmp.1
> $tmp.2
