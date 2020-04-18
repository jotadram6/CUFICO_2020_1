import numpy as np
import matplotlib.pyplot as plt

class Particula:
    
    def __init__(self,x,y,z,vx,vy,vz,m,c):

        self.Carga = c
        self.X, self.Y, self.Z = x,y,z
        self.Vx, self.Vy, self.Vz = vx,vy,vz
        self.Masa = m
        
        self.D = np.sqrt(self.X**2 + self.Y**2 + self.Z**2)

    def Pos_evol(self,ax,ay,az,t):

        self.X = self.X + (self.Vx*t) + (0.5*ax*(t*t))
        self.Y = self.Y + (self.Vy*t) + (0.5*ay*(t*t))
        self.Z = self.Z + (self.Vz*t) + (0.5*az*(t*t))
        
        self.Vx = self.Vx + ax*t
        self.Vy = self.Vy + ay*t
        self.Vz = self.Vz + az*t

# Main

P1 = Particula(0,0,0,0,0,0,10,1)
P2 = Particula(1,0,0,0,0,0,10,-1)
Bz = 10 # Intensidad de campo magnetico

X1, Y1, Z1 = [], [], []
X2, Y2, Z2 = [], [], []

for _ in np.arange(0,100,0.01):
    
    # Fuerza electrica de interaccion entre cargas
    Ex1 = - P1.Carga * P2.Carga /(P1.D - P2.D)**3 * (P1.X-P2.X)
    Ey1 = - P1.Carga * P2.Carga /(P1.D - P2.D)**3 * (P1.Y-P2.Y) 
    Ez1 = - P1.Carga * P2.Carga /(P1.D - P2.D)**3 * (P1.Z-P2.Z) 
    
    Ex2, Ey2, Ez2 = -Ex1, -Ey1, -Ez1
    
    # Fuerza magnetica de interaccion con el campo 
    Bx1 = Bz*P1.Vy ; By1 = -Bz*P1.Vx
    Bx2 = Bz*P2.Vy ; By2 = -Bz*P2.Vx
    
    # Aceleracion debido a las dos fuerzas
    
    ax1 = (Ex1+ Bx1)/P1.Masa ; ay1 = (Ey1+ By1)/P1.Masa ; az1 = Ez1/P1.Masa
    ax2 = (Ex2+ Bx2)/P2.Masa ; ay2 = (Ey2+ By2)/P2.Masa ; az2 = Ez2/P2.Masa

    
    P1.Pos_evol(ax1,ay1,az1,0.01)    
    P2.Pos_evol(ax2,ay2,az2,0.01)
    
    X1.append(P1.X) ; Y1.append(P1.Y) ; Z1.append(P1.Z)
    X2.append(P2.X) ; Y2.append(P2.Y) ; Z2.append(P2.Z)

# Graficacion

t = np.arange(0,100,0.01)

plt.plot(t,X1, color = "orange",label="x1")
plt.plot(t,Y1, color = "blue",label="y1")
plt.plot(t,Z1, color = "green",label="z1")

plt.plot(t,X2, color = "orange",ls = "--",label="x1")
plt.plot(t,Y2, color = "blue",ls = "--",label="y1")
plt.plot(t,Z2, color = "green",ls= "--",label="z1")

plt.legend(loc= "best")
plt.title("Python",fontsize=15)
plt.plot()
plt.grid()
plt.savefig("SegClasesPython.png")
plt.show()

