#!/bin/bash
#g++ monteCarlo.cpp -o monteCarlo
gcc -Wall -std=c99 -fopenmp parfor.c -o parfor -lm

file_1="parfor.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

./parfor >> parfor.dat