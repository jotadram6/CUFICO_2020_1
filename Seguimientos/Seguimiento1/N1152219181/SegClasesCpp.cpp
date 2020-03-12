#include <iostream>
#include <cmath>
class Particula{
public:
  int Carga;
  float X,Y,Z;
  float Vx,Vy,Vz;
  float M;
  float Bz;
  void SetValues(float,float,float,float,float,float,float,float,int);
  float Pos_evol(float);
  
  
}Par1,Par2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m, float bz, int C)
{
  X=x;
  Y=y;
  Z=z;
  Vx=vx;
  Vy=vy;
  Vz=vz;
  M=m;
  Bz=bz;
  Carga=C;
}

float Particula::Pos_evol(float t){
  float w=Bz*Carga/M;
  X=(Vx*sin(w*t)+Vy*(1-cos(w*t))/w) ;
  Y=(Vy*sin(w*t)+Vx*(cos(w*t)-1)/w) ;	 
  Z=Vz*t;
}


int main(){

  //Evolucion de la particula 1 y 2
  Par1.SetValues(0.0,0.0,0.0,1.0,0.0,1.0,10.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,-1.0,0.0,1.0,10.0,10.0,1);  
  for (int i=0; i<10000; i++){
    Par1.Pos_evol(i/0.01);
    Par2.Pos_evol(i/0.01);
    
    std::cout <<    Par1.X << "," << Par1.Y  << "," << Par1.Z  << "," <<    Par2.X << "," << Par2.Y  << "," << Par2.Z  << std::endl;}
  return 0; }	

