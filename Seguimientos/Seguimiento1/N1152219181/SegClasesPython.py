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
        self.Vx=vx
        self.Vy=vy
        self.Vz=vz
        self.M=m
        self.Bz=bz
        self.Carga=carga
    def Pos_evol(self,Fx,Fy,Fz,t):
       self.X=self.X+self.Vx*t+(0.5*t*t*Fx/self.M) 
       self.Y=self.Y+self.Vy*t+(0.5*t*t*Fy/self.M)       
       self.Z=self.Z+self.Vy*t+(0.5*t*t*Fz/self.M)   
       self.Vx=self.Vx+(Fx*t/self.M)
       self.Vy=self.Vy+(Fy*t/self.M)
       self.Vz=self.Vz+(Fz*t/self.M)

Par1=Particula(0.0,0.0,0.0,0.0,0.0,0.0,10.0,10.0,1)
Par2=Particula(1.0,0.0,0.0,0.0,0.0,0.0,10.0,10.0,-1)  
#print(Par1.X,Par1.Y,Par1.Z,Par1.VX,Par1.VY,Par1.VZ,Par1.M,Par1.Carga)
x1=[]
y1=[]
z1=[]

x2=[]
y2=[]
z2=[]
for i in range(10000):
    if ((Par2.X-Par1.X)**(2) + (Par2.Y-Par1.Y)**(2) + (Par2.Z-Par1.Z)**2)==0: break
    #Particula 1
    Fx1=(Par1.Vy*Par1.Bz*Par1.Carga)+((Par1.Carga*Par2.Carga)*(Par1.X-Par2.X)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    Fy1=-(Par1.Vx*Par1.Bz*Par1.Carga)+((Par1.Carga*Par2.Carga)*(Par1.Y-Par2.Y)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    Fz1=((Par1.Carga*Par2.Carga)*(Par1.Z-Par2.Z)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    
    #Particula 2
    Fx2=(Par2.Vy*Par2.Bz*Par2.Carga)+((Par1.Carga*Par2.Carga)*(Par2.X-Par1.X)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    Fy2=-(Par2.Vx*Par2.Bz*Par2.Carga)+((Par1.Carga*Par2.Carga)*(Par2.Y-Par1.Y)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    Fz2=((Par1.Carga*Par2.Carga)*(Par2.Z-Par1.Z)/((4*np.pi*(8.8541e-12))*((Par1.X-Par2.X)**(2)+(Par1.Y-Par2.Y)**(2)+(Par1.Z-Par2.Z)**(2))**(3/2)))
    
    Par1.Pos_evol(Fx1,Fy1,Fz1,0.1)
    x1.append(Par1.X)
    y1.append(Par1.Y)
    z1.append(Par1.Z)
    
    Par2.Pos_evol(Fx2,Fy2,Fz2,0.1)
    
    x2.append(Par2.X)
    y2.append(Par2.Y)
    z2.append(Par2.Z)

ax= plt.axes(projection= "3d")

ax.plot3D(x1,y1,z1,"green")
ax.plot3D(x2,y2,z2,"gray")
plt.show()    
   
    
