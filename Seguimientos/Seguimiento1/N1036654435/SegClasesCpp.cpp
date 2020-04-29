//realizado por: Sergio Duque Mej�a

#include <iostream>
using namespace std;
#include <cmath>

class particula
{
public:
  int Carga;
  float X,Y,Z;
  float VX,VY,VZ;
  float AX,AY,AZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,float,float,float,int);
  float evolA(int,float,float,float,float);
  float evolV(float);
  float evolP(float);

}P1,P2;

void particula::SetValues(float x,float y,float Ax,float Ay,float Az,float z,float Vx,float Vy,float Vz,float m,int q)
{
  X = x;
  Y = y;
  Z = z;
  VX = Vx;
  VY = Vy;
  VZ = Vz;
  AX = Ax;
  AY = Ay;
  AZ = Az;
  M = m;
  Carga = q;
}

float particula::evolA(int Bz,float d,float x1,float y1,float z1)
{
  int k=1;
  AX=-(k*(Carga*Carga)*x1)/(M*d)+(Carga*VY*Bz)/M;
  AY=-(k*(Carga*Carga)*y1)/(M*d)-(Carga*VX*Bz)/M;
  AZ=-(k*(Carga*Carga)*z1)/(M*d);
}

float particula::evolV(float t)
{
  VX=VX+AX*t;
  VY=VY+AY*t;
  VZ=VZ+AZ*t;
}

float particula::evolP(float t)
{
  X=X+(VX*t)+(0.5*AX*(t*t));
  Y=Y+(VY*t)+(0.5*AY*(t*t));
  Z=Z+(VZ*t)+(0.5*AZ*(t*t));
}


int main()
{

  int m=10;
  int q=1;
  int Bz=10;
  float t=0.01;

  
  P1.SetValues(0,0,0,0,0,0,0,0,0,m,q);
  P2.SetValues(1,0,0,0,0,0,0,0,0,m,-q);

  //cout << "PARTICULA 1: " << " x=" << P1.X  <<  " y=" << P1.Y << " z=" << P1.Z << " vx=" << P1.VX << " vy=" << P1.VY << " vz=" << P1.VZ << " ax=" << P1.AX << " ay=" << P1.AY << " az=" << P1.AZ << " masa=" << P1.M << " carga=" << P1.Carga << endl;
  
  //cout << "PARTICULA 2: " << " x=" << P2.X  <<  " y=" << P2.Y << " z=" << P2.Z << " vx=" << P2.VX << " vy=" << P2.VY << " vz=" << P2.VZ << " ax=" << P2.AX << " ay=" << P2.AY << " az=" << P2.AZ << " masa=" << P2.M << " carga=" << P2.Carga << endl;

  cout << "--------------------------------" << endl;

  for (int i=0; i<1000; i++)
    {
      float d = pow(((P1.X-P2.X)*(P1.X-P2.X)+(P1.Y-P2.Y)*(P1.Y-P2.Y)+(P1.Z-P2.Z)*(P1.Z-P2.Z)),3/2);
      float x1=(P2.X-P1.X);
      float y1=(P2.Y-P1.Y);
      float z1=(P2.Z-P1.Z);

      P1.evolA(Bz,d,x1,y1,z1);
      P2.evolA(Bz,d,x1,y1,z1);

      P1.evolV(t);
      P2.evolV(t);

      P1.evolP(t);
      P2.evolP(t);

      cout << P2.Y << endl;

      

     
      //cout << "PARTICULA 1: " << " x=" << P1.X  <<  " y=" << P1.Y << " z=" << P1.Z << " vx=" << P1.VX << " vy=" << P1.VY << " vz=" << P1.VZ << " ax=" << P1.AX << " ay=" << P1.AY << " az=" << P1.AZ << " masa=" << P1.M << " carga=" << P1.Carga << endl;

      //cout << "PARTICULA 2: " << " x=" << P2.X  <<  " y=" << P2.Y << " z=" << P2.Z << " vx=" << P2.VX << " vy=" << P2.VY << " vz=" << P2.VZ << " ax=" << P2.AX << " ay=" << P2.AY << " az=" << P2.AZ << " masa=" << P2.M << " carga=" << P2.Carga << endl;

    }
  return 0;
}
