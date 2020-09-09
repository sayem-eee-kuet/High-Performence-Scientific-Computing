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


ax = fig.gca(projection='3d')
surface_plot = ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm,
                               linewidth=0, antialiased=True)
# surface_plot = ax.plot_surface(X, Y, Z, rstride=1, cstride=1,
#                                linewidth=0, antialiased=True)
ax.set_xlabel(r'$x_1$')
ax.set_ylabel(r'$x_2$')
ax.set_zlabel('Ln(L)')
fig.colorbar(surface_plot, shrink=0.5, aspect=10)
# plt.show()
fig.savefig("Contour_plot_3d", bbox_inches="tight")
