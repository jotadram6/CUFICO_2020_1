#include <iostream>
#include <cmath>
using namespace std;

class Particula
{
public:
  int Carga;
  float X,Y,Z;
  float VX,VY,VZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,int, float);
}Q1,Q2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m,int e)
{
  X=x;
  Y=y;
  Z=z;
  VX=vx;
  VY=vy;
  VZ=vz;
  M=m;
  Carga=e;
}

float Particula::Pos_evol(float xx,float yy,float zz,int q, float t)
{
    float Bz=10.0;
    float k=9.0e9;
    float r=std::pow((X-xx)*(X-xx)+(Y-yy)*(Y-yy)+(Z-zz)*(Z-zz),1.5);
    float em=Carga/M;
    float Ex=k*q*((X-xx)/r);
    float Ey=k*q*((Y-yy)/r);
    float Ez=k*q*((Z-zz)/r);
    float a1=em*(Ex + (VY*Bz));
    float a2=em*(Ey - (VX*Bz));
    float a3=em*Ez;
  
    X=X+(VX*0.01);
    Y=Y+(VY*0.01);
    Z=Z+(VZ*0.01);
  
    VX=VX+(a1*0.01);
    VY=VY+(a2*0.01);
    VZ=VZ+(a3*0.01);
    return 0;
}

int main()
{
  
  Q1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,1);
  Q2.SetValues(1.0,0.0,0.0,0.0,0.0,0.0,10.0,-1);

    cout << "Asignación de valores iniciales de variables y valor de parámetros:" << endl;
  cout << "Particula 1:   Carga=" << Q1.Carga << ", x=" << Q1.X << ", y=" << Q1.Y << ", z=" << Q1.Z << ", vx=" << Q1.VX << ", vy=" << Q1.VY << ", vz=" << Q1.VZ << ", M=" << Q1.M  << endl;
    cout << "Particula 2:   Carga=" << Q2.Carga << ", x=" << Q2.X << ", y=" << Q2.Y << ", z=" << Q2.Z << ", vx=" << Q2.VX << ", vy=" << Q2.VY << ", vz=" << Q2.VZ << ", M=" << Q2.M  << endl;

  for (int i=1; i<10000; i++)
    {
        float X1=Q1.X, Y1=Q1.Y, Z1=Q1.Z, q1=Q1.Carga;
      Q1.Pos_evol(Q2.X, Q2.Y, Q2.Z, Q2.Carga, 0.01);        
      Q2.Pos_evol(X1, Y1, Z1, q1, 0.01);
      
     
    }
  
  cout << "Valor final 10000 iteraciones x, y, z, vx, vy, v:" << endl;
  cout << "Particula 1:   Carga=" << Q1.Carga << ", x=" << Q1.X << ", y=" << Q1.Y << ", z=" << Q1.Z << ", vx=" << Q1.VX << ", vy=" << Q1.VY << ", vz=" << Q1.VZ << ", M=" << Q1.M  << endl;
    cout << "Particula 2:   Carga=" << Q2.Carga << ", x=" << Q2.X << ", y=" << Q2.Y << ", z=" << Q2.Z << ", vx=" << Q2.VX << ", vy=" << Q2.VY << ", vz=" << Q2.VZ << ", M=" << Q2.M  << endl;
  
  return 0;

}
