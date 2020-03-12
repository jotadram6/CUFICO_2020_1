#include <iostream>
#include <cmath>
using namespace std;






class Particula{
public:
  int Carga;
  float X,Y,Z;
  float VX,VY,VZ;
  float M;
  void SetValues(float,float,float,float,float,float,float,int);
  float Pos_evol(float);
  
  
}Par1,Par2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m, int C)
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

float Particula::Pos_evol(float t){
  X=sin(t);
  Y=cos(t)-1;
  Z=t;
}
int main(){ 
    
    Par1.SetValues(1.0,0.0,0.0,1.0,0.0,0.0,1.0,1);

   
  
    
    for (int i=0; i<10000; i++){
      Par1.Pos_evol(i/0.01);

    
      cout <<  Par1.X <<","<< Par1.Y  <<","<< Par1.Z  << endl;}
  return 0;
}
