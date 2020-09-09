#!/bin/bash
g++ -Wall -o task1 task1.cpp
g++ -Wall -O3 -ffast-math -mavx -o task1_optimized task1.cpp 

file_1="task1.dat"
file_2="task1_optimized.dat"
file_3="task1_python.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

if [ -f $file_3 ] ; then
    rm $file_3
fi

time ./task1 >> $file_1
time ./task1_optimized >> $file_2
time python task1.py >> $file_3

python plot.py 