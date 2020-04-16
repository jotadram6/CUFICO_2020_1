#!/usr/bin/python
#from visual.graph import*
#from visual import*
#from math import*

import numpy as np
import matplotlib.pyplot as plt

box = 100 #Longitud del lado de la caja donde se desarrolla la simulacion
d_min = np.sqrt(2)/2 #Distancia minima de no contagio
t_sick = 250 #Tiempo que tarda la enfermedad

##########################
###Definicion de clases###
##########################

class person:

    def __init__(self, X=box*np.random.random(), Y=box*np.random.random(),
                 VX=-1 + 2*np.random.random(), VY=-1 + 2*np.random.random(),
                 STATUS='healthy', TIME_SICK=0):
        """Las personas se inician por defecto con una posicion y una velocidad
        aleatorias y saludables. Las posiciones se encuentran en el rango de 0
        a box (siendo box la longitud del lado de la caja donde se mueven las
        personas); las velocidades estan en el rango -1 a 1 tanto en x como y"""
        self.x = X
        self.y = Y
        self.vx = VX
        self.vy = VY
        self.status = STATUS
        self.time_sick = TIME_SICK

    def reset(self):
        """Reasigna una posicion y una velocidad aleatoria a una persona ya
        creada."""
        self.x = box*np.random.random()
        self.y = box*np.random.random()
        self.vx = -1 + 2*np.random.random()
        self.vy = -1 + 2*np.random.random()
        self.status = 'healthy'
        self.time_sick = 0
        
    def pos_evol(self, dt):
        """Evoluciona la posicion de la persona y si esta enferma toma el
        tiempo que lleva en esa condicion."""
        self.x = self.x + self.vx*dt
        self.y = self.y + self.vy*dt
        if self.status == 'sick':
            self.time_sick += dt

class population(list, person):
    """La clase population hereda de list y person. La clase population es un
    arreglo de personas."""
    
    def __init__(self, N):
        """Como argumento de inicializacion se pide el numero de personas en
        la poblacion"""
        for i in range(0, N):
            self.append(person())
            
        for i in range(0, N): #Se reasignan posiciones aleatorias a las personas
            self[i].reset() #Si no se hace todas quedan en la misma posicion

    def reset(self):
        for i in range(0, len(self)):
            self[i].reset()

    def pos_evol(self, dt):
        """Evoluciona la posicion de todas las personas de la poblacion"""
        for i in range(0, len(self)):
            self[i].pos_evol(dt) #Se actualiza la posicion de la persona i
            #Se restringe el movimiento a 0 <= x <= box
            if self[i].x <= 0 or self[i].x >= box:
                self[i].vx = -self[i].vx #La particula se refleja en los bordes
            #Se restringe el movimiento a 0 <= y <= box
            if self[i].y <= 0 or self[i].y >= box:
                self[i].vy = -self[i].vy #La particula se refleja en los bordes
            
    def status_evol(self):
        """Evoluciona el estado de salud de la poblacion"""
        for i in range(0, len(self)):
            if self[i].status == 'sick':
                #   Se mide la distancia entre la persona i, que esta enferma, y
                #cada una de las otras personas en la poblacion.
                for j in range(0,i)+range(i+1,len(self)):
                    #No se compara con si misma.
                    if self[j].status == 'healthy':
                        #Distancia entre la persona i y la persona j
                        d_ij = np.sqrt((self[i].x - self[j].x)**2
                                       +(self[i].y - self[j].y)**2)
                        if d_ij <= d_min:
                            self[j].status = 'sick'
                if self[i].time_sick >= t_sick:
                    self[i].status = 'recovered'

    def health(self):
        """Hace un conteo de las personas sanas, enfermas y recuperadas. Retor-
        na un arreglo cuya primera entrada tiene el numero de sanos; la segun-
        da, el numero de enfermos y las tercera, el numero de recuperados."""
        h = [0,0,0]
        for i in range(0, len(self)):
            if self[i].status == 'healthy':
                h[0] += 1
            elif self[i].status == 'sick':
                h[1] += 1
            elif self[i].status == 'recovered':
                h[2] += 1
        return h

##################
###SIMULACIONES###
##################
    
"""Primera simulacion: 200 personas que se mueven libremente y no interaccionan
entre si, solo con las paredes de la caja (como un gas ideal)."""

n = 200 #Numero de personas en la poblacion
p = population(n) #Se crea una poblacion de n personas
p[100].status = 'sick' #Se enferma la persona numero 100

h, s, r = [], [], [] #h: sanos. s: enfermos. r: curados
t = [] #t: tiempo

for i in range(0,1000):
    p.pos_evol(1)
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()


plt.xlabel('Tiempo (u.a.)')
plt.ylabel('Personas')
plt.suptitle('Primera simulaci$\\acute{o}$n: Todos libres')
plt.plot(t,h,label='sanos')
plt.plot(t,s,label='enfermos')
plt.plot(t,r,label='curados')
plt.legend(loc='center left')
plt.grid()
plt.show()


"""Segunda simulacion: 200 personas, las cuales se dividen en dos camaras, una
de 100x(100/3) y otra de 100x(200/3). En la primera se infecta una persona y se
deja evolucionar el sistema completamente aislado hasta cierto tiempo; luego se
abre una compuerta de tamano 20 y se deja evolucionar el sistema durante el
mismo tiempo, esta vez interactuando con el sistema donde todas las personas
estaban sanas; y por ultimo se abre una compuerta de tamano 40 durante el mismo
tiempo."""

p.reset() #Se reasignan posiciones y velocidades aleatorias
l = 100./3 #Posicion del muro de la caja de cuarentena
dl = 1 #Semiancho del muro de la caja de cuarentena. Ancho=2*dl y 2*dl>d_min
qua = [] #Aqui estaran las personas que inicialmente estan en cuarentena
free = [] #Aqui estaran las personas que se mueven libremente

for i in range(0, len(p)):
    #Se diferencia entre los que estan o no en cuarentena
    if p[i].x <= l:
        qua.append(i)
        if l - p[i].x <= dl: #Si la persona queda dentro del muro
            p[i].x = p[i].x - 1 #Se corre 1 hacia la izquierda
    else:
        free.append(i)
        if p[i].x - l <= dl: #Si la persona queda dentro del muro
            p[i].x = p[i].x + 1 #Se corre 1 hacia la derecha

p[qua[0]].status = 'sick' #Se infecta la persona 0 que esta en cuarentena

h, s, r = [], [], [] #h: sanos. s: enfermos. r: curados
t = [] #t: tiempo

for i in range(0,333):
    #Etapa en la que estan completamente aisladas las personas enfermas
    p.pos_evol(1)
    for j in qua:
        if p[j].x >= l - dl:
            p[j].vx = -p[j].vx
    for j in free:
        if p[j].x <= l + dl:
            p[j].vx = -p[j].vx
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()

for i in range(333,666):
    #Etapa en la que se abre una compuerta de tamano 20
    p.pos_evol(1)
    for j in qua:
        if (p[j].x >= l - dl) and (p[j].y < 40 or p[j].y > 60):
            p[j].vx = -p[j].vx
    for j in free:
        if (p[j].x <= l + dl) and (p[j].y < 40 or p[j].y > 60):
            p[j].vx = -p[j].vx
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()


for i in range(666,1000):
    #Etapa en la que se abre una compuerta de tamano 40
    p.pos_evol(1)
    for j in qua:
        if (p[j].x >= l - dl) and (p[j].y < 30 or p[j].y > 70):
            p[j].vx = -p[j].vx
    for j in free:
        if (p[j].x <= l + dl) and (p[j].y < 30 or p[j].y > 70):
            p[j].vx = -p[j].vx
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()
    

plt.xlabel('Tiempo (u.a.)')
plt.ylabel('Personas')
plt.suptitle('Segunda simulaci$\\acute{o}$n: Cuarentena rota')
plt.plot(t,h,label='sanos')
plt.plot(t,s,label='enfermos')
plt.plot(t,r,label='curados')
plt.legend(loc='center left')
plt.grid()
plt.show()

#Tercera simulacion: Se detiene a 3/4 de la poblacion, el resto son libres

p.reset() #Se reasignan posiciones y velocidades aleatorias

for i in range(0,3*n/4): #Se detiene a 3/4 de la poblacion
    p[i].vx = 0
    p[i].vy = 0

p[199].status = 'sick' #Se enferma la persona numero 199

h, s, r = [], [], [] #h: sanos. s: enfermos. r: curados
t = [] #t: tiempo

for i in range(0,1000):
    p.pos_evol(1)
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()

plt.xlabel('Tiempo (u.a.)')
plt.ylabel('Personas')
plt.suptitle('Tercera simulaci$\\acute{o}$n: ' +
             'Se detiene 3/4 de la poblaci$\\acute{o}$n')
plt.plot(t,h,label='sanos')
plt.plot(t,s,label='enfermos')
plt.plot(t,r,label='curados')
plt.legend(loc='center left')
plt.grid()
plt.show()


"""Cuarta simulacion: Se detiene a 7/8 de la poblacion, el resto son libres"""

p.reset() #Se reasignan posiciones y velocidades aleatorias

for i in range(0,7*n/8): #Se detiene a 7/8 de la poblacion
    p[i].vx = 0
    p[i].vy = 0

p[199].status = 'sick' #Se enferma la persona numero 199

h, s, r = [], [], [] #h: sanos. s: enfermos. r: curados
t = [] #t: tiempo

for i in range(0,1000):
    p.pos_evol(1)
    counter = p.health()
    h.append(counter[0])
    s.append(counter[1])
    r.append(counter[2])
    t.append(i)
    p.status_evol()


plt.xlabel('Tiempo (u.a.)')
plt.ylabel('Personas')
plt.suptitle('Cuarta simulaci$\\acute{o}$: ' +
             'Se detiene 7/8 de la poblaci$\\acute{o}$n')
plt.plot(t,h,label='sanos')
plt.plot(t,s,label='enfermos')
plt.plot(t,r,label='curados')
plt.legend(loc='center left')
plt.grid()
plt.show()
