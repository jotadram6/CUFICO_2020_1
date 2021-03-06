import matplotlib.pyplot as mplt

class Particula:
    #Atributos
    cargada=True
    
    ## Intancias
    def __init__(self,x,y,z,vx,vy,vz,ax,ay,az,m,carga):
        self.X=x
        self.Y=y
        self.Z=z
        self.Vx=vx
        self.Vy=vy
        self.Vz=vz
        self.M=m
        self.Carga=carga
        self.ax=ax
        self.ay=ay
        self.az=az
    def ac_evol(self,B,r3,posx,posy,posz):
        k=9e9
#        k=1
  
        self.ax=-(k*self.Carga**2*posx)/(self.M*r3)+(self.Carga*self.Vy*B)/self.M
        self.ay=-(k*self.Carga**2*posy)/(self.M*r3)-(self.Carga*self.Vx*B)/self.M
        self.az=-(k*self.Carga**2*posz)/(self.M*r3)
    def vel_evol(self,t):
        self.Vx=self.Vx+self.ax*t
        self.Vy=self.Vy+self.ay*t
        self.Vz=self.Vz+self.az*t   
    def Pos_evol(self,t):
        self.X=self.X+(self.Vx*t)+(0.5*self.ax*(t*t))
        self.Y=self.Y+(self.Vy*t)+(0.5*self.ay*(t*t))
        self.Z=self.Z+(self.Vz*t)+(0.5*self.az*(t*t))

m=10
carga=1
Par1= Particula(0,0,0,0,0,0,0,0,0,m,carga)
Par2=Particula(1e9,0,0,0,0,0,0,0,0,m,-carga)
t=0.01
B=10
print(Par1.X,Par1.Y,Par1.Z,Par1.Vx,Par1.Vy,Par1.Vz,Par1.M,Par1.Carga)
for i in range(1,10000):
    #Par1.Pos_evol(t)
                
    r3=((Par1.X-Par2.X)**2+(Par1.Y-Par2.Y)**2+(Par1.Z-Par2.Z)**2)**(3/2)
    posx=(Par2.X-Par1.X)
    posy=(Par2.Y-Par1.Y)
    posz=(Par2.Z-Par1.Z)
    
    Par1.ac_evol(B,r3,posx,posy,posz)
    Par2.ac_evol(B,r3,posx,posy,posz)
  
    Par1.vel_evol(t)
    Par2.vel_evol(t)
    Par1.Pos_evol(t)
    Par2.Pos_evol(t)
    mplt.plot(Par1.X,Par1.Y,'.',color='b')

mplt.xlabel('X')
mplt.ylabel('Y')
mplt.grid()
mplt.savefig('SegClasesPython.png')
mplt.show()
