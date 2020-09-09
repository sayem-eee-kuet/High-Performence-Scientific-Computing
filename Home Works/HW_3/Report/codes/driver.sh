#!/bin/bash
g++ -Wall -O3 -ffast-math -mavx -o mc10d_1_b mc10d_1_b.cpp -lm
g++ -Wall -O3 -ffast-math -mavx -o mc10d_1_b_time mc10d_1_b_time.cpp -lm
#g++ -Wall -o mc10d mc10d.cpp

file_1="dataSerial.dat"
file_2="timeData.dat"


if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi


i=9
./mc10d_1_b $((10**i)) >> dataSerial.dat
echo "Using C++ timer: " >> timeData.dat
./mc10d_1_b_time $((10**i)) >> timeData.dat
# time ./mc10d_1_b_time $((10**i)) >> timeData.dat


echo "Done! Check data file." 
python3 plot.py