#!/bin/bash
# lab/shell-scripts/lc-pwd.sh

echo Executing $(basename $0)...
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
