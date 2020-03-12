#include <iostream>
#include <cmath>


class Particle
{
public:
  int Carga;
  float X,Y,Z;
  float VX, VY, VZ;
  float M;
  void SetValues(float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,float);
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
float Particle::Pos_evol(float w, float t)
{
  X=sin(w*t);
  Y=cos(w*t)-1
  Z=VX*t
}

int main(){

Par1.SetValues(0.0,0.0,0.0,1.0,0.0,0.0,10.0,1);
 for (int i=0; i<10000; i++){
      Par1.Pos_evol(1.0,i/0.01);
      std::cout << "Carga=" << Par1.Carga << ", x=" <<   Par1.X  << ", y=" << Par1.Y  << ", z=" << Par1.Z << ", vx="<< Par1.VX << ", vy="<< Par1.VY   << ", vz="<< Par1.VZ << ", M=" << Par1.M << std::endl;
 }

  return 0;
}
