#!/bin/bash

#Task 2, problem a
echo "Task 2, problem a starts..."
python3 baisian_contour.py
python3 baisian_3d.py
echo "Task 2, problem a ends..."

#Task 2, problem b
echo "Task 2, problem b starts..."
chmod +x likelihood.sh
./likelihood.sh
echo "Task 2, problem b ends..."


#Task 2, problem c
echo "Task 2, problem c ends..."
chmod +x likelihood.sh
./likelihood_time.sh
echo "Task 2, problem c ends..."