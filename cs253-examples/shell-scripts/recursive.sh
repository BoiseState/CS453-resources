#!/bin/bash

holeinmybucket() {
	let depth++
	echo "depth = " $depth
	holeinmybucket
}

holeinmybucket

