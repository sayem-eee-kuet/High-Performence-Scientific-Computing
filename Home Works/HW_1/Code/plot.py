#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression

# you can inspect this from jupyter notebook; its a matrix of your data
data = np.loadtxt('data.dat')
data1 = np.loadtxt('avgErrdata.dat')  # Data for calculating avg Err
data2 = np.loadtxt('trapData.dat')  # Data from trapizoidal rule
#data3 = np.loadtxt('time.dat')
xv = data[:, 0]  # ":" means grab all of the rows, and 0 is from column 0
yv = data[:, 1]

xa = data1[:, 0]
ya = data1[:, 1]

x_t = data2[:, 0]
y_t = data2[:, 1]

# Theoritical error of MC: err is proportional to Itr^(-1/2)
# y_theory = np.array(1./np.sqrt(data[:, 0])
# print(y_theory)


sum_xa = 0
sum_ya = 0.0

# Avg Error calculation
maxi = 30  # if this value is changed, then must be changed in dataScript.sh file too
maxj = 200  # 200 # if this value is changed, then must be changed in dataScript.sh file too
mean_xa = []
mean_ya = []
j = 0
for i in range(0, maxi):
    for j in range(0, maxj):
        #print(j, int(data1[i*maxj + j, 0]))
        sum_xa = sum_xa + int(data1[i*maxj + j, 0])
        sum_ya = sum_ya + data1[i*maxj + j, 1]

    mean_xa.append(sum_xa/maxj)
    mean_ya.append(sum_ya/maxj)
    sum_xa = 0
    sum_ya = 0.0


itr_a = np.array(mean_xa)
err_a = np.array(mean_ya)

log_itr_a = np.log10(itr_a)
log_err_a = np.log10(err_a)
# print(log_itr_a)
# print(log_err_a)


# Problem e: log <E(N)> = Alog(N) + B
# Linear Regreesion
model = LinearRegression(False).fit(
    (log_itr_a.reshape(-1, 1)), log_err_a)  # y-intercept is False
model.score((log_itr_a.reshape(-1, 1)), log_err_a)
#print('coefficient of determination:', r_sq)
#print('intercept:', model.intercept_)
print('A = ', model.coef_[0])


# Plotting
fig = plt.figure()

plt.loglog(xv, yv, 'blue', label='E(n)', marker='o',
           markerfacecolor='blue', markersize=4)
plt.loglog(itr_a, err_a, 'red', label='<E(n)>', marker='o',
           markerfacecolor='red', markersize=4)
plt.loglog(x_t, y_t, 'green', label='E(trap)', marker='o',
           markerfacecolor='green', markersize=4)
plt.loglog(xv, 1./np.sqrt(data[:, 0]), 'black', label='E(Th)', marker='o',
           markerfacecolor='black', markersize=4)

plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Iteration')
plt.ylabel('Error')
#plt.title('Numerical Intergration: Err vs Iteration')
# plt.show()
fig.savefig("Numerical_Intergration_Err_vs_Iteration.png",
            bbox_inches="tight")
