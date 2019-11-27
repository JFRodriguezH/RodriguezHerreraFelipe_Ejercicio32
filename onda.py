from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("onda.dat")

Nx = len(data[0, :])-1

x = np.linspace(-1,1,Nx)
t = data[:, 0]
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure(figsize=(12,4))
plt.subplot(131)
plt.imshow(Z, aspect=0.1)
plt.subplot(132)
plt.plot(t, Z[:, int(Nx/2)])
plt.plot(t, Z[:, int(Nx/3)])
plt.plot(t, Z[:, int(Nx/4)])
plt.plot(t, Z[:, int(Nx/5)])
plt.plot(t, Z[:, int(Nx/6)])
plt.tight_layout()
plt.subplot(133)
plt.plot(x, Z[0, :])

plt.savefig("onda.png")