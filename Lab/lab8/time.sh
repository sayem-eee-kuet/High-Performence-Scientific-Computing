#!/bin/bash

file_1="time.dat"
file_2="trap_ompl2.dat"
file_3="trap_ompl1.dat"

# if [ -f $file_1 ] ; then
#     rm $file_1
# fi

# if [ -f $file_2 ] ; then
#     rm $file_2
# fi

# if [ -f $file_3 ] ; then
#     rm $file_3
# fi
# echo "Trap_serial_time: N = 10**9" | tee time.dat
# /usr/bin/time -f "%e" ./trapezoidal 1000000000 &>> time.dat
# echo "Trap_ompl1_time: N = 10**9" | tee time.dat
# /usr/bin/time -f "%e" ./trap_ompl1 1000000000 &>> time.dat
# echo "Trap_ompl2_time: N = 10**9" | tee time.dat
# /usr/bin/time -f "%e" ./trap_ompl2 1000000000 &>> time.dat

echo "Trap_serial_time: N = 10**9" #| tee time.dat
time (./trapezoidal 1000000000) 
echo "Trap_ompl1_time: N = 10**9" #| tee time.dat
time (./trap_ompl1 1000000000) 
echo "Trap_ompl2_time: N = 10**9" #| tee time.dat
time (./trap_ompl2 1000000000) 