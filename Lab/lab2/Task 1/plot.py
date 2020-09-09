#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt

f2 = open('CPUData1.dat', 'r')
lines = f2.readlines()
f2.close()

x1 = []
y1 = []

for line in lines:
    p = line.split()
    x1.append(float(p[0]))
    y1.append(float(p[1]))
   
xv = np.array(x1)
yv = np.array(y1)

fig = plt.figure()
plt.plot(xv,yv,'blue',label='y')
#plt.legend()
plt.xlabel('Date')
plt.ylabel('%CPU Usage')
plt.title(r'Firefox CPU Usage')

fig.savefig("CPU_Usage.png", bbox_inches="tight")
