#!/bin/bash
subTask=b
# export GMON_OUT_PREFIX=gmon.out-
#mpiCC secret_function.o -Wall -pg -o task2_$subTask task2_$subTask.cpp -lm -no-pie 
mpiCC -O3 -ffast-math -mavx secret_function.o -Wall -pg -o task2_$subTask task2_$subTask.cpp -lm -no-pie
#g++ secret_function.o -Wall -pg -o task2_$subTask task2_$subTask.cpp -lm -no-pie 
#g++ -Wall -O1 -ffast-math -mavx secret_function.o -pg -o task2_$subTask task2_$subTask.cpp -lm -no-pie
#g++ -Wall -O1 secret_function.o -pg -o task2_$subTask task2_$subTask.cpp -lm -no-pie

file_1="task2_$subTask.dat"
file_2="Profiling_output_$subTask.dat"



if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi



threadNo=1
N=1000

mpirun -np $threadNo task2_$subTask $N >> $file_1

# ./task2_$subTask $N >> $file_1

gprof task2_$subTask gmon.out >> $file_2

# gprof -s task2_a gmon.out-

# gprof task2_a gmon.sum