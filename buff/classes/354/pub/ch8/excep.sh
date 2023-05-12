#!/bin/bash

Error() {
    echo "not ok"
    exit 1;
}

trap "Error" SIGUSR1

foo() {
    if [ $# -lt 1 ] ; then
	kill -SIGUSR1 $$
    fi
    # much more code
    echo "foo() done"
}

foo "$@"
# much more code
echo "ok"
