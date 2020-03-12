#include <iostream> //equivale al import de Python
using namespace std; //equivale al "from lib import *" en Python

class Particula
{
public:
  int Carga;
  float X,Y,Z;
  float VX,VY,VZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,int,float);
}Par1,Par2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m,int C) //:: como cuando se llaman elementos de una libreria
{
  X=x;
  Y=y;
  Z=z;
  VX=vx;
  VY=vy;
  VZ=vz;
  M=m;
  Carga=C;
}

float Particula::Pos_evol(float x2,float y2,float z2,int Q,float t)
{
    float Bz=10.0;
    float k0=8.99e9;

  r3=((X-x2)**2+(Y-y2)**2+(Z-z2)**2)**(1.5);
        
  ax=(Carga/M)*((k0*Q*(X-x2)/r3) + (VY*Bz));
  ay=(Carga/M)*((k0*Q*(Y-y2)/r3) - (VX*Bz));
  az=(Carga/M)*(k0*Q*(Z-z2)/r3);
  
  X=X+(VX*t)+(0.5*ax*(t*t));
  Y=Y+(VY*t)+(0.5*ay*(t*t));
  Z=Z+(VZ*t)+(0.5*az*(t*t));
  
  VX=VX+(ax*t);
  VY=VY+(ay*t);
  VZ=VZ+(az*t);
  return 0;
}

int main()
{
  
  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,0.0,0.0,0.0,10.0,-1);

    cout << "Los estados de las particulas al principio son:" << endl;
  cout << "Particula 1:   Carga=" << Par1.Carga << ", x=" << Par1.X << ", y=" << Par1.Y << ", z=" << Par1.Z << ", vx=" << Par1.VX << ", vy=" << Par1.VY << ", vz=" << Par1.VZ << ", M=" << Par1.M  << endl;
    cout << "Particula 2:   Carga=" << Par2.Carga << ", x=" << Par2.X << ", y=" << Par2.Y << ", z=" << Par2.Z << ", vx=" << Par2.VX << ", vy=" << Par2.VY << ", vz=" << Par2.VZ << ", M=" << Par2.M  << endl;

  for (int i=1; i<10001; i++)
    {
        float X1=Par1.X, Y1=Par1.Y, Z1=Par1.Z, Q1=Par1.Carga;
      Par1.Pos_evol(Par2.X, Par2.Y, Par2.Z, Par2.Carga, 0.01);        
      Par2.Pos_evol(X1, Y1, Z1, Q1, 0.01);
      
     
    }
  
  cout << "Los estados de las particulas despues de 10 mil iteraciones son:" << endl;
  cout << "Particula 1:   Carga=" << Par1.Carga << ", x=" << Par1.X << ", y=" << Par1.Y << ", z=" << Par1.Z << ", vx=" << Par1.VX << ", vy=" << Par1.VY << ", vz=" << Par1.VZ << ", M=" << Par1.M  << endl;
    cout << "Particula 2:   Carga=" << Par2.Carga << ", x=" << Par2.X << ", y=" << Par2.Y << ", z=" << Par2.Z << ", vx=" << Par2.VX << ", vy=" << Par2.VY << ", vz=" << Par2.VZ << ", M=" << Par2.M  << endl;
  
  return 0;

}

