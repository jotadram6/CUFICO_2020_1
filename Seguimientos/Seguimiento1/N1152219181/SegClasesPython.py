#!/usr/bin/python
import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

class Particula:
    #atributos
    cargada= True
    #Instancias
    def __init__(self,x,y,z,vx,vy,vz,m,bz,carga):
        self.X=x
        self.Y=y
        self.Z=z
        self.VX=vx
        self.VY=vy
        self.VZ=vz
        self.M=m
        self.Bz=bz
        self.Carga=carga
    def Pos_evol(self,t):
        w=self.Bz*self.Carga/self.M;
        self.X=(self.VX*np.sin(w*t)+self.VY*(1-np.cos(w*t))/w) ;
        self.Y=(self.VY*np.sin(w*t)+self.VX*(np.cos(w*t)-1)/w) ;	 
        self.Z=self.VZ*t;
Par1=Particula(0.0,0.0,0.0,1.0,0.0,1.0,10.0,10.0,1)
Par2=Particula(1.0,0.0,0.0,-1.0,0.0,1.0,10.0,10.0,1)  
#print(Par1.X,Par1.Y,Par1.Z,Par1.VX,Par1.VY,Par1.VZ,Par1.M,Par1.Carga)
x1=[]
y1=[]
z1=[]

x2=[]
y2=[]
z2=[]
for i in range(10000):
    Par1.Pos_evol(i*0.01)
    x1.append(Par1.X)
    y1.append(Par1.Y)
    z1.append(Par1.Z)
    
    Par2.Pos_evol(i*0.01)
    
    x2.append(Par2.X)
    y2.append(Par2.Y)
    z2.append(Par2.Z)

ax= plt.axes(projection= "3d")

ax.plot3D(x1,y1,z1,"green")
ax.plot3D(x2,y2,z2,"gray")
plt.show()    
   
    
