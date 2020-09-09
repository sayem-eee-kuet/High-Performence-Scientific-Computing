#!/bin/bash
mpiCC -Wall -o problem5 problem5.cpp

file_1="problem5.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

for threadNo in 2 5 10 100
#for threadNo in 1000
do
  echo "Number of player $threadNo" >> problem5.dat
  echo "-------------------------------------------" >> problem5.dat
  mpirun -np $threadNo problem5 >> problem5.dat
  echo "===========================================" >> problem5.dat
done

echo "Done! Check data file!"



