#!/bin/bash

while [ "1" == "1" ]
do
cpuUsage=`ps -A -o %cpu | sort -n | tail -n 1`

echo "$cpuUsage"
sleep 1
./CPU_usage $cpuUsage

done