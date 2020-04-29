import pandas as pd
import matplotlib.pylab as plt

particula1x = pd.read_csv("/home/usuario/par1.txt")
particula1y = pd.read_csv("/home/usuario/par2.txt")
particula2x = pd.read_csv("/home/usuario/par3.txt")
particula2y = pd.read_csv("/home/usuario/par4.txt")

plt.plot(particula1x,particula1y, "o", color="b")
plt.plot(particula2x,particula2y, "o", color="g")
plt.title("Cinematica de particulas con cargas opuestas")
plt.xlabel("x")
plt.ylabel("y")
plt.grid()
plt.show()
