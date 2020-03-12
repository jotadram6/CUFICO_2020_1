//realizado por: Sergio Duque Mejía

#include <iostream>
using namespace std;

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

void particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m,int c)
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
  AX=-(k*Carga**2*x1)/(M*d)+(Carga*VY*Bz)/M;
  AY=-(k*Carga**2*y1)/(M*d)-(Carga*VX*Bz)/M;
  AZ=-(k*Carga**2*z1)/(M*d);
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
  int k=1;
  
  p1.SetValues(0,0,0,0,0,0,0,0,0,m,q);
  p2.SetValues(1,0,0,0,0,0,0,0,0,m,-q);

  for (int i=0; i<1000; i++)
    {
      d=((p1.X-p2.X)**2+(p1.Y-p2.Y)**2+(p1.Z-p2.Z)**2)**(3/2);
      x1=(p2.X-p1.X);
      y1=(p2.Y-p1.Y);
      z1=(p2.Z-p1.Z);

      p1.evoA(Bz,d,x1,y1,z1);
      p2.evoA(Bz,d,x1,y1,z1);

      p1.evoV(t);
      p2.evoV(t);

      p1.evoP(t);
      p2.evoP(t);

    }
}
