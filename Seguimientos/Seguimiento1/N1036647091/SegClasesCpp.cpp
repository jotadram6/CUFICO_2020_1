#include <iostream>
#include <cmath>

//Como B=10 y M=10 y  W=Bq/M entonces W=Q=1 
class Particula{
public:
  int Carga;
  float X,Y,Z;
  float Vx,Vy,Vz;
  float M;
  float Bz;
  void SetValues(float,float,float,float,float,float,float,float,int);
  float Pos_evol(float,float,float,float);
  
  
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

float Particula::Pos_evol(float Fx,float Fy, float Fz,float t){
  float w=Bz*Carga/M;
 
  X=X+(Vx*t)+(0.5*Fx*(t*t));
  Y=Y+(Vy*t)+(0.5*Fx*(t*t));
  Z=Z+(Vz*t)+(0.5*Fx*(t*t));
  Vx=Vx+(Fx*t/M);
  Vy=Vy+(Fy*t/M);
  Vz=Vz+(Fz*t/M);
}

int main(){

  //Evolucion de la particula 1 y 2
  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,0.0,0.0,1.0,10.0,10.0,1);
  for (int i=0; i<10000; i++){

    if ((pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2))==0) break;
      
    float Fx1=Par1.Vy-1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    float Fy1=-Par1.Vx-1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    float Fz1=1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);

    float Fx2=Par1.Vy-1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    float Fy2=-Par1.Vx-1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    float Fz2=1/pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1/2);
    
    Par1.Pos_evol(Fx1,Fy1,Fz1,i*0.01);
    Par2.Pos_evol(Fx2,Fy2,Fz2,i*0.01);

    
    std::cout <<    Par1.X << "," << Par1.Y  << "," << Par1.Z  << "," <<    Par2.X << "," << Par2.Y  << "," << Par2.Z  << std::endl;
  }
  return 0; }	




