import matplotlib
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def ln_fqn(x1, x2):
    return -np.power(1.-x1, 2.0) - 100.*np.power(x2-np.power(x1, 2.0), 2.0)


def x_values(start, stop, step=0.001):
    delta = step
    start = float(start)
    stop = float(stop)
    x = np.arange(start, stop, delta)
    return x


#fig = plt.figure(figsize=(7, 6))
fig = plt.figure()
# left, bottom, width, height = 0.1, 0.1, 0.8, 0.8
# ax = fig.add_axes([left, bottom, width, height])

X, Y = np.meshgrid(x_values(-5, 5, 0.1), x_values(-5, 5, 0.1))
Z = ln_fqn(X, Y)

#Z = np.sqrt(X**2 + Y**2)
# fig, ax = plt.subplots()
# CS = ax.contour(X, Y, Z)
CS = plt.contourf(X, Y, Z, cmap=cm.coolwarm)  # contourf(X, Y, Z)
plt.colorbar(CS)
#ax.clabel(CS, inline=1, fontsize=10)
# fig.set_title('Contour Plot 'r'$L(x_{1}, x_{2};M_1)$')
# fig.set_xlabel(r'$x_{1}$')
# fig.set_ylabel(r'$x_{2}$')

plt.grid(True)
plt.minorticks_on()
# Customize the major grid
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel(r'$x_{1}$')
plt.ylabel(r'$x_{2}$')
plt.title('Contour Plot 'r'$L(x_{1}, x_{2};M_1)$')
# plt.show()
fig.savefig("Contour_plot", bbox_inches="tight")

# ax1 = fig.gca(projection='3d')
# surface_plot = ax1.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm,
#                                linewidth=0, antialiased=True)
# ax1.set_xlabel(r'$x_1$')
# ax1.set_ylabel(r'$x_2$')
# ax1.set_zlabel('Ln(L)')
# fig.colorbar(surface_plot, shrink=0.5, aspect=10)
# plt.show()
# fig.savefig("Contour_plot_3d", bbox_inches="tight")
