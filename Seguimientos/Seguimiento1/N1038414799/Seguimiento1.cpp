#include <iostream>
#include <cmath>


class Particle
{
public:
  int Carga;
  float X,Y,Z;
  float VX, VY, VZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,float);
  float acelerationx(float, float ,float ,float, float,float,float, float,float, float, int, int, int , float);
  float deno(float, float ,float ,float, float,float,float, float,float, float, int, int, int , float);
  float acelerationy(float, float ,float ,float, float,float,float, float,float, int, int,int, int , float);
  float acelerationz(float, float ,float ,float, float,float,float, float,float, int, int, int ,int, float);

  //void time_slice_print();
} Par1, Par2;

void Particle::SetValues(float x,float y,float z,float vx,float vy,float vz,float m,int C)
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

float Particle::Pos_evol(float ax, float ay, float az, float t)
{
  X=X+VX*t+(0.5*(ax)*t*t);
  Y=Y+VY*t+(0.5*(ay)*t*t);
  Z=Z+VZ*t+(0.5*(az)*t*t);
  VX=VX+(ax*t);
  VY=VY+(ay*t);
  VZ=VZ+(az)*t;
  
}

float Particle::acelerationx(float x1, float x2,float velx,float y1, float y2,float vely,float z1, float z2,float velz, float mass, int q1,int q2, int k, float w)

{
  
  float den = pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2);
  float acx = vely*w-(q1*q2*(x1-x2))/(mass*k*pow(den,1.5));
  return acx;
}
float Particle::deno(float x1, float x2,float velx,float y1, float y2,float vely,float z1, float z2,float velz, float mass, int q1,int q2, int k, float w)

{
  
  float den = pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2);
  return den;
}

float Particle::acelerationy(float x1, float x2,float velx,float y1, float y2,float vely,float z1, float z2,float velz, int mass, int q1,int q2, int k, float w){
  
  float den = pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2);
  float acy = -velx*w-(q1*q1*(x1-x2))/(mass*k*pow(den,1.5));
  return acy;

		      }
float Particle::acelerationz(float x1, float x2,float velx,float y1, float y2,float vely,float z1, float z2,float velz, int mass, int q1,int q2, int k, float w){
  
  float den = pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2);
  float acz = (q1*q2*(x1-x2))/(mass*k*pow(den,1.5));
  return acz;

  } 			 
					  
int main(){

  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,0.0,0.0,0.0,10.0,-1);
for (int i=0; i<10000; i++){

  if (Par1.deno(Par1.X,Par2.X,Par1.VX,Par1.Y,Par2.Y,Par1.VY,Par1.Z,Par2.Z,Par1.VZ,Par1.M,Par1.Carga,Par2.Carga,1,1.0)==0) {break;}

  float AX1=Par1.acelerationx(Par1.X,Par2.X,Par1.VX,Par1.Y,Par2.Y,Par1.VY,Par1.Z,Par2.Z,Par1.VZ,Par1.M,Par1.Carga,Par2.Carga,1,1.0);
  float AY1=Par1.acelerationy(Par1.X,Par2.X,Par1.VX,Par1.Y,Par2.Y,Par1.VY,Par1.Z,Par2.Z,Par1.VZ,Par1.M,Par1.Carga,Par2.Carga,1,1.0);
  float AZ1=Par1.acelerationz(Par1.X,Par2.X,Par1.VX,Par1.Y,Par2.Y,Par1.VY,Par1.Z,Par2.Z,Par1.VZ,Par1.M,Par1.Carga,Par2.Carga,1,1.0);

  float AX2=Par2.acelerationx(Par2.X,Par1.X,Par2.VX,Par2.Y,Par1.Y,Par2.VY,Par2.Z,Par1.Z,Par2.VZ,Par2.M,Par2.Carga,Par1.Carga,1,1.0);
  float AY2=Par2.acelerationx(Par2.X,Par1.X,Par2.VX,Par2.Y,Par1.Y,Par2.VY,Par2.Z,Par1.Z,Par2.VZ,Par2.M,Par2.Carga,Par1.Carga,1,1.0);
  float AZ2=Par2.acelerationx(Par2.X,Par1.X,Par2.VX,Par2.Y,Par1.Y,Par2.VY,Par2.Z,Par1.Z,Par2.VZ,Par2.M,Par2.Carga,Par1.Carga,1,1.0);
      
   Par1.Pos_evol(AX1,AY1,AZ1,0.01);
   Par2.Pos_evol(AX2,AY2,AZ2,0.01);

      
   std::cout << Par1.X  << "," << Par1.Y << "," << Par1.Z << "," << Par2.X << "," << Par2.Y << "," << Par2.Z << std::endl;
   }

  return 0;
}
