#!/usr/bin/python
# coding: utf-8
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import style
import numpy as np

Bz=10.0 #Magnitud del campo magnético en la dirección z
k=9.0e9 #Valor aproximado constante de Coulomb [N*m^2/C^2]
N=10000 #Número de iteraciones
t=0.0
dt=0.01 #Paso de tiempo

class Particula:
    #Atributos
    cargada = True

    #Instancias
    def __init__(self,x,y,z,vx,vy,vz,m,carga):
        self.X=x
        self.Y=y
        self.Z=z
        self.VX=vx
        self.VY=vy
        self.VZ=vz
        self.M=m
        self.e=carga

    def lorentz(self, xx, yy, zz, q):
        em=(self.e/self.M) #Relación Carga Masa y Separación Partículas r^3
        r=((self.X-xx)**2+(self.Y-yy)**2+(self.Z-zz)**2)**(1.5)
        
        #Componentes del campo Electrico
        Ex=k*q*(self.X-xx)/r
        Ey=k*q*(self.Y-yy)/r
        Ez=k*q*(self.Z-zz)/r

        #Componentes de la aceleración
        a1=em*(Ex + (self.VY*Bz))
        a2=em*(Ey - (self.VX*Bz))
        a3=em*Ez
        
        #Actualización posiciones
        pos1=self.X=self.X+(self.VX*dt)
        pos2=self.Y=self.Y+(self.VY*dt)
        pos3=self.Z=self.Z+(self.VZ*dt)
        
        #Actualización velocidades
        vel1=self.VX=self.VX+(a1*dt)
        vel2=self.VY=self.VY+(a2*dt)
        vel3=self.VZ=self.VZ+(a3*dt)

#Asignación de valores iniciales de variables y valor de parámetros
I1=Particula(1.0,0.0,0.0,0.0,0.0,0.0,10.0,1)
I2=Particula(0.0,0.0,0.0,0.0,0.0,0.0,10.0,-1)

print("Valor inicial x, y, z, vx, vy, vz")
print("Partícula 1:")
print(I1.X,I1.Y,I1.Z,I1.VX,I1.VY,I1.VZ)
print("Partícula 2:")
print(I2.X,I2.Y,I2.Z,I2.VX,I2.VY,I2.VZ)

x1=[]
y1=[]
z1=[]
x2=[]
y2=[]
z2=[]

for i in range(N-1):
    Paso=np.array([I1.X,I1.Y,I1.Z,I1.VX,I1.VY,I1.VZ,I1.M,I1.e])
    I1.lorentz(I2.X, I2.Y, I2.Z, I2.e)        
    I2.lorentz(Paso[0], Paso[1], Paso[2], Paso[7])
    x1=np.append(x1,I1.X)
    y1=np.append(y1,I1.Y)
    z1=np.append(z1,t)
    x2=np.append(x2,I2.X)
    y2=np.append(y2,I2.Y)
    z2=np.append(z2,t)
    t+=dt

print("Valor final 10000 iteraciones x, y, z, vx, vy, vz")
print("Partícula 1:")
print(I1.X,I1.Y,I1.Z,I1.VX,I1.VY,I1.VZ)
print("Partícula 2:")
print(I2.X,I2.Y,I2.Z,I2.VX,I2.VY,I2.VZ)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot(x1,y1,z1,c='r')
ax.plot(x2,y2,z2,c='b')
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
plt.show()
