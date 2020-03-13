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
  
    X=X+Vx*t+(0.5*t*t*Fx/M) ;
    Y=Y+Vy*t+(0.5*t*t*Fy/M) ;
    Z=Z+Vy*t+(0.5*t*t*Fz/M) ;
    Vx=Vx+(Fx*t/M);
    Vy=Vy+(Fy*t/M);
    Vz=Vz+(Fz*t/M);
}


int main(){

  //Evolucion de la particula 1 y 2
  Par1.SetValues(0.0,0.0,0.0,0.0,0.0,0.0,10.0,10.0,1);
  Par2.SetValues(1.0,0.0,0.0,0.0,0.0,0.0,10.0,10.0,-1);  
  for (int i=0; i<10000; i++){
    if ((pow((Par2.X-Par1.X),2) + pow((Par2.Y-Par1.Y),2) + pow((Par2.Z-Par1.Z),2))==0) break;
    //Particula 1
    float Fx1=Par1.Vy*Par1.Bz*Par1.Carga+(Par1.Carga*Par2.Carga*(Par1.X-Par2.X)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));
    float Fy1=-Par1.Vx*Par1.Bz*Par1.Carga+(Par1.Carga*Par2.Carga*(Par1.Y-Par2.Y)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));
    float Fz1=(Par1.Carga*Par2.Carga*(Par1.Z-Par2.Z)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));
    //Particula2
    float Fx2=Par2.Vy*Par2.Bz*Par2.Carga+(Par1.Carga*Par2.Carga*(Par2.X-Par1.X)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));
    float Fy2=-Par2.Vx*Par2.Bz*Par2.Carga+(Par1.Carga*Par2.Carga*(Par2.Y-Par1.Y)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));
    float Fz2=(Par1.Carga*Par2.Carga*(Par2.Z-Par1.Z)/(4*M_PI*(8.8541e-12)*pow((pow((Par1.X-Par2.X),2)+pow((Par1.Y-Par2.Y),2)+pow((Par1.Z-Par2.Z),2)),1.5)));


    
    Par1.Pos_evol(Fx1,Fy1,Fz1,0.1);
    Par2.Pos_evol(Fx2,Fy2,Fz2,0.1);
    
    std::cout <<    Par1.X << "," << Par1.Y  << "," << Par1.Z  << "," <<    Par2.X << "," << Par2.Y  << "," << Par2.Z  << std::endl;}
  return 0; }	

