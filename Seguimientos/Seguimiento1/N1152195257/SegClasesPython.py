#!/usr/bin/python

import numpy as np
import matplotlib.pyplot as plt

k = 10 #Constante de Coulomb

###########################
####Definicion de clases###
###########################

class particle:

    def __init__(self, X, Y, Z, VX, VY, VZ, AX, AY, AZ, m, q):
        self.x = np.float64(X)
        self.y = np.float64(Y)
        self.z = np.float64(Z)
        self.vx = np.float64(VX)
        self.vy = np.float64(VY)
        self.vz = np.float64(VZ)
        self.ax = np.float64(AX)
        self.ay = np.float64(AY)
        self.az = np.float64(AZ)
        self.mass = m
        self.charge = q

    def pos_evol(self, t):
        self.x = self.x + (self.vx*t) + (0.5*self.ax*(t*t))
        self.vx = self.vx + self.ax*t
        self.y = self.y + (self.vy*t) + (0.5*self.ay*(t*t))
        self.vy = self.vy + self.ay*t
        self.z = self.z + (self.vz*t) + (0.5*self.az*(t*t))
        self.vz = self.vz + self.az*t

class Electric_field:

    def __init__(self, X, Y, Z):
        self.x = X
        self.y = Y
        self.z = Z

class Magnetic_field:

    def __init__(self, X, Y, Z):
        self.x = X
        self.y = Y
        self.z = Z

class Lorentz_force:

    def __init__(self, X, Y, Z):
        self.x = X
        self.y = Y
        self.z = Z

###############################
####Definicion de funciones####
###############################

def E_field(A, B):
    """Campo electrico generado por la particula A en la posicion de B"""
    r = np.sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z))
    rho = np.sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y))
    sin_theta = rho/r
    cos_theta = (B.z-A.z)/r
    sin_phi = (B.y-A.y)/rho
    cos_phi = (B.x-A.x)/rho
    E = Electric_field(0.0, 0.0, 0.0)
    EE = k/(r*r)
    E.x = A.charge*EE*sin_theta*cos_phi
    E.y = A.charge*EE*sin_theta*sin_phi
    E.z = A.charge*EE*cos_theta
    return E

#Se establecen las condiciones iniciales
B = Magnetic_field(0.0, 0.0, 10.0)
F1 = Lorentz_force(0.0, 0.0, 0.0)
F2 = Lorentz_force(0.0, 0.0, 0.0)
par1 = particle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1)
par2 = particle(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, -1)

for i in range(0, 10000):
    #Fuerza de Lorentz sobre la particula 1
    F1.x = par1.charge*(E_field(par2,par1).x + par1.vy*B.z - par1.vz*B.y)
    F1.y = par1.charge*(E_field(par2,par1).y + par1.vz*B.x - par1.vx*B.z)
    F1.z = par1.charge*(E_field(par2,par1).z + par1.vx*B.y - par1.vy*B.x)
    #Se actualizan las aceleraciones de la particula 1
    par1.ax = F1.x/par1.mass
    par1.ay = F1.y/par1.mass
    par1.az = F1.z/par1.mass

    #Fuerza de Lorentz sobre la particula 2
    F2.x = par2.charge*(E_field(par1,par2).x + par2.vy*B.z - par2.vz*B.y)
    F2.y = par2.charge*(E_field(par1,par2).y + par2.vz*B.x - par2.vx*B.z)
    F2.z = par2.charge*(E_field(par1,par2).z + par2.vx*B.y - par2.vy*B.x)
    #Se actualizan las aceleraciones de la particula 2
    par2.ax = F2.x/par2.mass
    par2.ay = F2.y/par2.mass
    par2.az = F2.z/par2.mass      
    
    #Se actualizan las posiciones y velocidades
    par1.pos_evol(0.01)
    par2.pos_evol(0.01)

    print par1.x, par1.y, par1.z, par2.x, par2.y, par2.z
    if i == 0:
        sol = np.array([[par1.x, par1.y, par1.z, par2.x, par2.y, par2.z]])
    else:
        sol = np.append(sol, np.array([[par1.x, par1.y, par1.z, par2.x, par2.y, par2.z]]), axis=0)

x1 = sol[:,0]
y1 = sol[:,1]
x2 = sol[:,3]
y2 = sol[:,4]

plt.plot(x1,y1)
plt.plot(x2,y2)
plt.plot(x1[-1],y1[-1], 'oc', label='Final position particle 1')
plt.plot(x2[-1],y2[-1], 'om', label='Final position particle 2')
plt.xlabel('$X$')
plt.ylabel('$Y$')
plt.legend(loc='center')
plt.grid()
plt.show()
