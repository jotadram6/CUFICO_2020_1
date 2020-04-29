#!/home/jhoan_eusse/anaconda3/bin/python

from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt


class Particula:
    cargada=True
    def __init__(self,x,y,z,vx,vy,vz,m,C):
        self.X=x
        self.Y=y
        self.Z=z
        self.VX=vx
        self.VY=vy
        self.VZ=vz
        self.M=m
        self.Carga=C

    def Pos_evol(self, w,t):
        self.X=np.sin(w*t)
        self.Y=np.cos(w*t)-1
        self.Z=self.VZ*t
            
    
Par1=Particula(0,0,0,1.0,0,0,10.0,1)
Par2=Particula(1,0,0,-1.0,0,0,10.0,1)
    
x1=[]
y1=[]
z1=[]

x2=[]
y2=[]
z2=[]

for i in range(10000):
      Par1.Pos_evol(1.0,i*0.01)
      x1.append(Par1.X)
      y1.append(Par1.Y)
      z1.append(Par1.Z)

      Par2.Pos_evol(1.0,i*0.01)
      x2.append(Par2.X)
      y2.append(Par2.Y)
      z2.append(Par2.Z)

ax = plt.axes(projection='3d')

ax.plot3D(x1,y1,z1,'green')
ax.plot3D(x2,y2,z2,'red')


plt.show()




