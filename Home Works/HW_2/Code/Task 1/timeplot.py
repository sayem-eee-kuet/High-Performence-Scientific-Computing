#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression


data = np.loadtxt('time.dat')

index = data[:, 0]
x_time = data[:, 1] / 1000
y_err = data[:, 2]

##### Avg Runtime Calculation #####
unique_elements, counts_elements = np.unique(index, return_counts=True)
frqn = int(counts_elements.mean())
print(frqn)

# Avg Error calculation
maxi = int(len(index)/frqn)
maxj = frqn
sum_xa = 0.0
sum_ya = 0.0
mean_xa = []
mean_ya = []
j = 0
for i in range(0, maxi):
    for j in range(0, maxj):
        #print(j, int(data1[i*maxj + j, 0]))
        sum_xa = sum_xa + (data[i*maxj + j, 1])
        sum_ya = sum_ya + data[i*maxj + j, 2]

    mean_xa.append(sum_xa/maxj)
    mean_ya.append(sum_ya/maxj)
    sum_xa = 0
    sum_ya = 0.0

x_time = np.array(mean_xa)
y_err = np.array(mean_ya)

# print(x_time)
# print(y_err)


#### Regrassion Model ####
#### T(E) = mE + c ####
x_time_log = np.log10(x_time)
y_err_log = np.log10(y_err)

y = x_time_log.reshape(-1, 1)
x = y_err_log.reshape(-1, 1)
# print(y_time)
model = LinearRegression(True).fit(x, y)
c = model.intercept_
m = model.coef_

# print(m)
# print(c)
E = -16
T = int(m * E + c)
print("With acuracy E = 1e-16 takes 1e{} sec".format(T))
E = -70030
T = int(m * E + c)
print("With acuracy E = 1e-70030 takes 1e{} sec".format(T))

#### Apprimate Final Model ####
T = np.array([x_time])
T = np.arange(10**-3, 10**6, 10**1)
E = 0.005 * T**(-1/2)

#### Plotting ####
fig = plt.figure()
plt.loglog(x_time, y_err, 'Black', label='Error vs Iteration,N', marker='o',
           markerfacecolor='red', markersize=4)
plt.loglog(T, E, 'blue', label='Approximate Model')
plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.xlabel('Runtime (s)')
plt.ylabel('Error ' r'$|\pi - \pi_{N}|$')
#plt.title('Time vs Number of Sample point curve')
# plt.show()
fig.savefig("Error_vs_wall_time_curve.png",
            bbox_inches="tight")
