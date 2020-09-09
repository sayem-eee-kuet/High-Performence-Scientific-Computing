#!/bin/bash
task=1_a
g++ -Wall -o task$task task$task.cpp

file_1="task$task.dat"


if [ -f $file_1 ] ; then
    rm $file_1
fi

echo "Test case..." >> $file_1
./task$task 1.4 >> $file_1

echo "Program..." >> $file_1
i=0
end=(10**4)
while [[ i -le end ]]
do
    ./task$task $i >> $file_1
    ((i = i + 1))
done