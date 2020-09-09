#!/bin/bash
mpiCC secret_function.o -Wall -o task1_b_cpp task1_b.cpp -lm -no-pie #&>> $file_2
#mpicc secret_function.o -Wall -std=c99 -o task1_a_c task1_a.c -lm &>> $file_3

file_1="task1_b.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

threadNo=4
N=2

mpirun -np $threadNo task1_b_cpp $N >> $file_1