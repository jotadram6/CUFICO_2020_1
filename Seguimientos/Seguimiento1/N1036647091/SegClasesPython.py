#!/usr/bin/env python
# coding: utf-8

# In[5]:


from mpl_toolkits import mplot3d
get_ipython().run_line_magic('matplotlib', 'inline')
import numpy as np
import matplotlib.pyplot as plt


# In[23]:


#!/usr/bin/python
class Particula:
    
    cargada= True
    
    def __init__(self,x,y,z,vx,vy,vz,m,carga):
        self.X=x
        self.Y=y
        self.Z=z
        self.VX=vx
        self.VY=vy
        self.VZ=vz
        self.M=m
        self.Carga=carga
    def Pos_evol(self,t):
        self.X=np.sin(t)
        self.Y=(np.cos(t)-1)
        self.Z=t
Par1=Particula(1.0,0.0,0.0,1.0,1.0,1.0,1.0,1)

for i in range(1,10000,1):

    Par1.Pos_evol(0.1)
    print(Par1.X,Par1.Y,Par1.Z)
    
    


# In[ ]:





# In[ ]:




