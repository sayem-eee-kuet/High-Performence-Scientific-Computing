#!/bin/bash
g++ -Wall problem1.cpp -o problem1
#$ TIMEFORMAT=%e
file_2="problem1.dat"
if [ -f $file_2 ] ; then
    rm $file_2
fi

# for (( i=1; i<=30; i++ ))
# do 
# 	/usr/bin/time -f "%e"  ./monteCarlo_time $((2**i)) &>> time.dat
#      #( time (./monteCarlo_time $((2**i)))) &>> time.dat
# done
# python3 timePlot.py
echo "For N = 4..." >> $file_2
N=4
./problem1 $N >> $file_2 

echo "For N = 10..." >> $file_2
N=10
./problem1 $N >> $file_2 

echo "For N = 30..." >> $file_2
N=30
./problem1 $N >> $file_2 