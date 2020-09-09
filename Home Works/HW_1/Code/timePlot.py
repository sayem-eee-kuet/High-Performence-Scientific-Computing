#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression

data3 = np.loadtxt('time.dat')

x_time = np.array([(2 ** i) for i in range(1, 31)])
y_time = np.array(data3[:])

# preditc N = 2^32 = ?? 
x_time = (x_time).reshape(-1, 1)
y_time = (y_time)
#print(y_time)
model = LinearRegression(True).fit(x_time, y_time)
x_predict = np.array(2**32)
y_predict = model.predict(x_predict.reshape(-1, 1))
model.score(x_time.reshape(-1, 1),y_time)
#print('coefficient of determination:', r_sq)
# print('intercept:', model.intercept_)
# print('solpe = ', model.coef_)
# print(y_predict[0])

# model 
N = 2.0**np.arange(19,32,1)
T = 2.17309336e-08 * N + 5.439183466774900e-3 

#Plotting
fig = plt.figure()
plt.loglog(x_time, y_time, 'blue', label='Linux: time vs iteration', marker='*',
           markerfacecolor='blue', markersize=10)
plt.loglog(N, T,'r', label='Model:' r'$T = 2.173e-08 \times N + 5.439e-3$', marker='o',
           markerfacecolor='red', markersize=4)
plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.xlabel('Number of Sample point')
plt.ylabel('Times(sec)')
#plt.title('Time vs Number of Sample point curve')
#plt.show()
fig.savefig("Time_vs_Number_of_Sample_point_curve.png",
            bbox_inches="tight")
