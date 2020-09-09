#!/bin/bash
g++ -Wall -o likelihood_fqn_time likelihood_fqn_time.cpp

file_1="likelihood_time.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

k=9
for (( i=1; i<=5; i++ ))
do 
/usr/bin/time -f "%e"  ./likelihood_fqn_time $((10**k)) &>> likelihood_time.dat
     #( time (./monteCarlo_time $((2**i)))) &>> time.dat
echo "i = "$i "is done!"
done