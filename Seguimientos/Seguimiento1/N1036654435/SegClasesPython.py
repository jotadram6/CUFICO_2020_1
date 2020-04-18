## Realizado por: Sergio Duque Mejía

#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import matplotlib.pylab as plt

m=10
q=1
Bz=10
t=0.01

class particula:
    cargada = True

    def __init__(self, x,y,z,Vx,Vy,Vz,Ax,Ay,Az,m,q):
        self.X = x
        self.Y = y
        self.Z = z
        self.VX = Vx
        self.VY = Vy
        self.VZ = Vz
        self.AX = Ax
        self.AY = Ay
        self.AZ = Az
        self.M = m
        self.Carga = q

    def evoA(self,Bz,d,x1,y1,z1):
        k=1
        self.AX=-(k*self.Carga**2*x1)/(self.M*d)+(self.Carga*self.VY*Bz)/self.M
        self.AY=-(k*self.Carga**2*y1)/(self.M*d)-(self.Carga*self.VX*Bz)/self.M
        self.AZ=-(k*self.Carga**2*z1)/(self.M*d)
    def evoV(self,t):
        self.VX=self.VX+self.AX*t
        self.VY=self.VY+self.AY*t
        self.VZ=self.VZ+self.AZ*t
    def evoP(self,t):
        self.X=self.X+(self.VX*t)+(0.5*self.AX*(t*t))
        self.Y=self.Y+(self.VY*t)+(0.5*self.AY*(t*t))
        self.Z=self.Z+(self.VZ*t)+(0.5*self.AZ*(t*t))

p1 = particula(0,0,0,0,0,0,0,0,0,m,q)
p2 = particula(1,0,0,0,0,0,0,0,0,m,-q)

for i in range(1,10000):
    d=((p1.X-p2.X)**2+(p1.Y-p2.Y)**2+(p1.Z-p2.Z)**2)**(3/2)
    x1=(p2.X-p1.X)
    y1=(p2.Y-p1.Y)
    z1=(p2.Z-p1.Z)

    p1.evoA(Bz,d,x1,y1,z1)
    p2.evoA(Bz,d,x1,y1,z1)

    p1.evoV(t)
    p2.evoV(t)

    p1.evoP(t)
    p2.evoP(t)

    plt.plot(p1.X,p1.Y,".",color="b")

plt.show()


# In[ ]:




