#!/bin/bash
file_2="cpp_compile_error.dat"
file_3="c_compile_error.dat"

if [ -f $file_2 ] ; then
    rm $file_2
fi

if [ -f $file_3 ] ; then
    rm $file_3
fi

mpiCC secret_function.o -Wall -o task1_a_cpp task1_a.cpp -lm -no-pie #&>> $file_2
#mpicc secret_function.o -Wall -std=c99 -o task1_a_c task1_a.c -lm &>> $file_3

file_1="task1_a.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

threadNo=4
N=4

mpirun -np $threadNo task1_a_cpp $N >> $file_1