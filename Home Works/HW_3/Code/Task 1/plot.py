#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from statistics import mean
from collections import Counter
# #from sklearn.linear_model import LinearRegression
# from sklearn import linear_model
# from sklearn.metrics import mean_squared_error, r2_score


data_1 = np.loadtxt('dataSerial.dat')
# data_2 = np.loadtxt('trap_ompl1.dat')
# data_3 = np.loadtxt('trap_ompl2.dat')


N = data_1[:, 0]
err = data_1[:, 2]
# log_N = np.log10(N)
# log_err = np.log10(err)

# # y_2 = data_2[:, 1]
# # y_3 = data_3[:, 1]
# # Linear Regreesion
# model = LinearRegression(False).fit(
#     (log_N.reshape(-1, 1)), log_err.reshape(-1, 1))  # y-intercept is False
# #model.score((log_itr_a.reshape(-1, 1)), log_err_a)
# #print('coefficient of determination:', r_sq)
# #print('intercept:', model.intercept_)
# print('A = ', model.coef_[0])


# Plotting
fig = plt.figure()
plt.loglog(N, err, 'black', label='Error per step',
           marker='o', markerfacecolor='red', markersize=4)
## Theoritical error of MC: err is proportional to Itr ^ (-1/2) ###
plt.loglog(N, 1200/np.sqrt(N), 'blue', label='Theory:'r'$E(N)\propto N^{-1/2}$', marker='o',
           markerfacecolor='black', markersize=4)
# plt.loglog(N, y_3, 'green', label='trap_ompl2 Error', marker='o',
#            markerfacecolor='red', markersize=4)

plt.legend()
plt.grid(True)
plt.minorticks_on()
# Customize the major grid
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Iteration, N')
plt.ylabel('Error per step')
# plt.title('Numerical Intergration: Err vs Iteration')
# plt.show()
fig.savefig("avg_Err_vs_Iteration.png", bbox_inches="tight")
plt.show()
