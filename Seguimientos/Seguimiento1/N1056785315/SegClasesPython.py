#!/usr/bin/python
#Definicion de una clase para describir una particula
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

Bz=10.0
k0=8.99e9 #[N*m^2/C^2]

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
        self.q=carga

    def Pos_evol(self, x2, y2, z2, Q, t):
    
        r3=((self.X-x2)**2+(self.Y-y2)**2+(self.Z-z2)**2)**(1.5)
        
        ax=(self.q/self.M)*((k0*Q*(self.X-x2)/r3) + (self.VY*Bz))
        ay=(self.q/self.M)*((k0*Q*(self.Y-y2)/r3) - (self.VX*Bz))
        az=(self.q/self.M)*(k0*Q*(self.Z-z2)/r3)
        
        self.X=self.X+(self.VX*t)+(0.5*ax*(t*t))
        self.Y=self.Y+(self.VY*t)+(0.5*ay*(t*t))
        self.Z=self.Z+(self.VZ*t)+(0.5*az*(t*t))
        
        self.VX=self.VX+(ax*t)
        self.VY=self.VY+(ay*t)
        self.VZ=self.VZ+(az*t)        
        
Par1=Particula(0.0,0.0,0.0,0.0,0.0,0.0,10.0,1)
Par2=Particula(1.0,0.0,0.0,0.0,0.0,0.0,10.0,-1)

print("Los estados de las particulas al principio son:")
print(Par1.X,Par1.Y,Par1.Z,Par1.VX,Par1.VY,Par1.VZ,Par1.M,Par1.q)
print(Par2.X,Par2.Y,Par2.Z,Par2.VX,Par2.VY,Par2.VZ,Par2.M,Par2.q)
print("\n")

x1=np.array([])
y1=np.array([])
z1=np.array([])
x22=np.array([])
y22=np.array([])
z22=np.array([])

for i in range(1,10001):
    Par11=np.array([Par1.X,Par1.Y,Par1.Z,Par1.VX,Par1.VY,Par1.VZ,Par1.M,Par1.q])
    Par1.Pos_evol(Par2.X, Par2.Y, Par2.Z, Par2.q, 0.01)        
    Par2.Pos_evol(Par11[0], Par11[1], Par11[2], Par11[7], 0.01)
    x1=np.append(x1,Par1.X)
    y1=np.append(y1,Par1.Y)
    z1=np.append(z1,Par1.Z)
    x22=np.append(x22,Par2.X)
    y22=np.append(y22,Par2.Y)
    z22=np.append(z22,Par2.Z)

print("Los estados de las particulas despues de 10 mil iteraciones son:")
print(Par1.X,Par1.Y,Par1.Z,Par1.VX,Par1.VY,Par1.VZ,Par1.M,Par1.q)
print(Par2.X,Par2.Y,Par2.Z,Par2.VX,Par2.VY,Par2.VZ,Par2.M,Par2.q)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(x1,y1,z1,c='g',linewidth=0.7)
ax.plot(x22,y22,z22,c='b',linewidth=0.7)
ax.scatter(Par1.X,Par1.Y,Par1.Z,c='r')
ax.scatter(Par2.X,Par2.Y,Par2.Z,c='r')

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
plt.savefig("SegClasesPython.png")
