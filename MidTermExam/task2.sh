#!/bin/bash
mpiCC -fopenmp -Wall -o task2 task2.cpp


mpirun -np 3 task2

echo "======="

mpirun -np 8 task2