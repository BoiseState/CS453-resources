#!/bin/bash

g() {
    local i=2			# late/shallow	
    $1
}

closure() {
    local i=1			# early/deep
    f() {
	echo $i
    }
    g f
}

closure
