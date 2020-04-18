#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


class Particle:

    
    cargada = True

    

    def __init__(self, x, y, z, vx, vy, vz, m, carga):

        self.X=x
        self.Y=y
        self.Z=z
        self.VX=vx
        self.VY=vy
        self.VZ=vz
        self.M=m
        self.Carga=carga
    

    def Fuerza(self, Ex, Ey, Ez):

        BZ = 10.0
        Fx = self.Carga*(Ex + self.VY*BZ)
        Fy = self.Carga*(Ey - self.VX*BZ)
        Fz = self.Carga*Ez

        return Fx,Fy,Fz

        
    def Vel_evol(self, ax, ay, az, t):

        self.VX = self.VX + ax*t
        self.VY = self.VY + ay*t
        self.VZ = self.VZ + az*t


    def Pos_evol(self, ax, ay, az, t):

       self.X = self.X + (self.VX * t) + (0.5*ax*t*t)
       self.Y = self.Y + (self.VY * t) + (0.5*ay*t*t)
       self.Z = self.Z + (self.VZ * t) + (0.5*az*t*t)
       

P1 = Particle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1)
P2 = Particle(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, -1)



x1 = []
y1 = []
z1 = []

x2 = []
y2 = []
z2 = []

for i in range(0, 10000):
    if ((P2.X-P1.X)**(2) + (P2.Y-P1.Y)**(2) + (P2.Z-P1.Z)**(2)) == 0: break

    Ex2 = (P2.Carga*(P1.X-P2.X))/(4*np.pi*(8.8541e-12)*((P1.X-P2.X)**(2) + (P1.Y-P2.Y)**(2) + (P1.Z-P2.Z)**(2))**(3/2))
    Ey2 = (P2.Carga*(P1.Y-P2.Y))/(4*np.pi*8.8541e-12*((P1.X-P2.X)**(2) + (P1.Y-P2.Y)**(2) + (P1.Z-P2.Z)**(2))**(3/2))
    Ez2 = (P2.Carga*(P1.Z-P2.Z))/(4*np.pi*8.8541e-12*((P1.X-P2.X)**(2) + (P1.Y-P2.Y)**(2) + (P1.Z-P2.Z)**(2))**(3/2))
    
    Ex1 = (P1.Carga*(-P1.X+P2.X))/(4*np.pi*8.8541e-12*((P2.X-P1.X)**(2) + (P2.Y-P1.Y)**(2) + (P2.Z-P1.Z)**(2))**(3/2))
    Ey1 = (P1.Carga*(-P1.Y+P2.Y))/(4*np.pi*8.8541e-12*((P2.X-P1.X)**(2) + (P2.Y-P1.Y)**(2) + (P2.Z-P1.Z)**(2))**(3/2))
    Ez1 = (P1.Carga*(-P1.Z+P2.Z))/(4*np.pi*8.8541e-12*((P2.X-P1.X)**(2) + (P2.Y-P1.Y)**(2) + (P2.Z-P1.Z)**(2))**(3/2))

    Fx, Fy, Fz =P1.Fuerza(Ex2, Ey2, Ez2)
    Fx2, Fy2, Fz2 =P2.Fuerza(Ex1, Ey1, Ez1)
    
    P1.Vel_evol(Fx/P1.M, Fy/P1.M, Fz/P1.M, 0.1)
    P1.Pos_evol(Fx/P1.M, Fy/P1.M, Fz/P1.M, 0.1)
    P2.Vel_evol(Fx2/P2.M, Fy2/P2.M, Fz2/P2.M, 0.1)
    P2.Pos_evol(Fx2/P2.M, Fy2/P2.M, Fz2/P2.M, 0.1)
 

    x1.append(P1.X)
    y1.append(P1.Y)
    z1.append(P1.Z)

    x2.append(P2.X)
    y2.append(P2.Y)
    z2.append(P2.Z)
    


fig = plt.figure(figsize = (10,10))
ax = Axes3D(fig)
ax.plot(x1,y1,z1)
ax.plot(x2,y2,z2)

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')


plt.legend()
plt.show()




