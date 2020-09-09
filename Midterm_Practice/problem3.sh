#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o problem3 problem3.cpp -lm

redSox="RedSox_2016"
yankess="Yankess_2016"
test="test"

rScore=878
rAllowed=694

yScore=680
yAllowed=702


file_1="problem3_$test.dat"
file_2="problem3_$redSox.dat"
file_3="problem3_$yankess.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

if [ -f $file_3 ] ; then
    rm $file_3
fi

./problem3 100 100 >> problem3_$test.dat
./problem3 $rScore $rAllowed >> problem3_$redSox.dat
./problem3 $yScore $yAllowed >> problem3_$yankess.dat

echo "Done! Check data file!"