#include <iostream>
#include <math.h>
using namespace std;

class particula
{
public:
  int Carga;
  float X,Y,Z;
  float Vx, Vy, Vz;
  float ax,ay,az;
  float M;

  void SetValues(float,float,float,float,float,float,float,float,float,float,int);
  float vel_evol(float);
  float ac_evol(float,float,float,float,float);
  float Pos_evol(float);
  
}Par1,Par2;
void particula :: SetValues (float x, float y, float z, float vx, float vy, float vz,float ax,float ay,float az,float m, int C)
{X=x;
  Y=y;
  Z=z;
  Vx=vx;
  Vy=vy;
  Vz=vz;
  ax=ax;
  ay=ay;
  az=az;
  M=m;
  Carga=C;
}
float particula :: ac_evol (float B, float r3, float posx,float posy,float posz)
{
  float k=9e9;
  
  ax=-(k*pow(Carga,2)*posx)/(M*r3)+(Carga*Vy*B)/M;
  ay=-(k*pow(Carga,2)*posy)/(M*r3)-(Carga*Vx*B)/M;
  az=-(k*pow(Carga,2)*posz)/(M*r3);

  return 0;
    }
float particula :: vel_evol (float t)
{
  Vx=Vx+ax*t;
  Vy=Vy+ay*t;
  Vz=Vz+az*t;   

  return 0;
}
float particula :: Pos_evol (float t)
{
  X=X+(Vx*t)+(0.5*ax*(t*t));
  Y=Y+(Vy*t)+(0.5*ay*(t*t));
  Z=Z+(Vz*t)+(0.5*az*(t*t));

  return 0;
}

int main()
{float t=0.01;
  float B=10.0;
  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,10.0,1);
  Par2.SetValues(1e9,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,10.0,-1);
  for (int i=0;i<10000; i++)
    {
      
      float r3=pow(pow(Par1.X-Par2.X,2)+pow(Par1.Y-Par2.Y,2)+pow(Par1.Z-Par2.Z,2),(3/2));
      float posx=(Par2.X-Par1.X);
      float posy=(Par2.Y-Par1.Y);
      float posz=(Par2.Z-Par1.Z);
    
      Par1.ac_evol(B,r3,posx,posy,posz);
      Par2.ac_evol(B,r3,posx,posy,posz);
  
      Par1.vel_evol(t);
      Par2.vel_evol(t);
      Par1.Pos_evol(t);
      Par2.Pos_evol(t);
      cout << Par1.X << "," << Par1.Y <<endl;
      
    }
  return 0;     
  
}
