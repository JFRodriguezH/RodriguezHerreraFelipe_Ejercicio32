from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("onda.dat")

Nx = len(data[0, :])-1

x = np.linspace(0,1,Nx)
t = data[:, 0]
Nt = len(t)
X, T = np.meshgrid(x, t)
Z = data[:, 1:]
plt.figure(figsize=(12,4))

plt.subplot(131)
plt.title("Nx = "+str(Nx)+"; Nt = "+str(Nt))
plt.ylabel("t")
plt.xlabel("x")
plt.imshow(Z, aspect=0.1)
plt.subplot(132)
plt.ylabel("\phi")
plt.xlabel("x")
for i in range(9):
	plt.plot(x, Z[int(i*Nt/9), :], label="t = "+str(np.round(t[int(i*Nt/9)], 2)))
plt.legend(loc="upper right")
plt.tight_layout()
plt.subplot(133)
plt.ylabel("\phi(x=L/4)")
plt.xlabel("t")
plt.plot(t, Z[:, int(Nx/4)])

plt.savefig("onda.png")