#!/bin/bash

i=10;
until [ $i -lt 1 ]; do
    let i--
    echo $i
done

