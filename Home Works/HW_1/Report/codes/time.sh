#!/bin/bash
g++ monteCarlo_time.cpp -o monteCarlo_time
#$ TIMEFORMAT=%e
file_2="time.dat"
if [ -f $file_2 ] ; then
    rm $file_2
fi

for (( i=1; i<=30; i++ ))
do 
	/usr/bin/time -f "%e"  ./monteCarlo_time $((2**i)) &>> time.dat
     #( time (./monteCarlo_time $((2**i)))) &>> time.dat
done
python3 timePlot.py
