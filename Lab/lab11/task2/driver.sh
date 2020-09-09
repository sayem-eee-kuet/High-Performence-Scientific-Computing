#!/bin/bash
gcc -o1 -Wall -std=c99 -fopenmp -o parfor parfor-fixed.c -lm
time ./parfor 1000000

gcc -o2 -Wall -std=c99 -fopenmp -o parfor parfor-fixed.c -lm
time ./parfor 1000000

gcc -o3 -Wall -std=c99 -fopenmp -o parfor parfor-fixed.c -lm
time ./parfor 1000000

gcc -ffast-math -Wall -std=c99 -fopenmp -o parfor parfor-fixed.c -lm
time ./parfor 1000000

gcc -mavx -Wall -std=c99 -fopenmp -o parfor parfor-fixed.c -lm
time ./parfor 1000000

