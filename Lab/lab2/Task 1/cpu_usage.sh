#!/bin/bash


MYPID=6843
echo "PID IS" $MYPID
ps -p $MYPID -o comm

while [ "1" == "1" ]
do
	x=`date +%s`
	y=`ps -p 6843 -o %cpu | tail -n 1`
	sleep 1
	echo $x $y
done
