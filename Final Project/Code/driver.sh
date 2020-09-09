#!/bin/bash

make

file_1="wave.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi
c=0.8
numProcess=4
time mpirun -np $numProcess wave $c &>> $file_1
#python plot.py