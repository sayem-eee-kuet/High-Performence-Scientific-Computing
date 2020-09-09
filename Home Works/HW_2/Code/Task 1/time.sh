#!/bin/bash
g++ -Wall -o monteCarlopi_time monteCarlopi_time.cpp

file_1="time.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

# for (( i=2; i<=10; i++ ))
# do 
# 	#/usr/bin/time -f "%e"  ./monteCarlo_time $((2**i)) &>> time.dat
#     ./monteCarlopi_time $((10**i)) >> time.dat
#     echo "i = "$i "is done"
# done

i=2
while [[ i -le 10 ]]
do
echo "i = "$i "starts"
    for (( j=1; j<=10; j++ ))
	   do
		./monteCarlopi_time $((10**i)) >> time.dat
	   done
echo "i = "$i "is done"
((i = i + 1))
done

python3 timeplot.py