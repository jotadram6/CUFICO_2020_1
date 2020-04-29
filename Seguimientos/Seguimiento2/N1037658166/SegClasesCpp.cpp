#include <iostream>
#include <cmath>
using namespace std;

class Particula
{
public:
  int Carga;
  float X,Y,Z;
  float Vx,Vy,Vz;
  float Masa;
  
  float D;
  
  void SetValues(float,float,float,float,float,float,float,int );
  float Pos_evol(float,float,float,float);
  
}P1,P2;

void Particula::SetValues(float x,float y,float z,float vx,float vy,float vz,float m,int C)
{
  X = x; Y = y; Z = z;
  Vx = vx; Vy = vy; Vz = vz;
  Masa = m;
  Carga = C;
  D = sqrt(X*X + Y*Y + Z*Z);
}

float Particula::Pos_evol(float ax,float ay,float az,float t)
{
  X = X + (Vx*t) + (0.5*ax*(t*t));
  Y = Y + (Vy*t) + (0.5*ay*(t*t));
  Z = Z + (Vz*t) + (0.5*az*(t*t));

  Vx = Vx + ax*t;
  Vy = Vy + ay*t;
  Vz = Vz + az*t;
  return 0;
}

int main()
{
  float Bz = 10; // Campo magnetico
  
  P1.SetValues(0,0,0,0,0,0,10,1);
  P2.SetValues(1.0,0,0,0,0,0,10,-1);
  
  for (int i=0;i<10000;i++)
    {
      
      // Fuerza electrica de interaccion entre cargas
      float g = P1.Carga * P2.Carga /pow(P1.D - P2.D,3);
								   
      float  Ex1 = - g * (P1.X-P2.X);
      float  Ey1 = - g * (P1.Y-P2.Y);
      float  Ez1 = - g * (P1.Z-P2.Z);

      float Ex2 = -Ex1; float Ey2 = -Ey1; float Ez2 = -Ez1;

      // Fuerza magnetica de interaccion con el campo

      float Bx1 = Bz*P1.Vy ; float By1 = -Bz*P1.Vx;
      float Bx2 = Bz*P2.Vy ; float By2 = -Bz*P2.Vx;

      //  Aceleracion debido a las dos fuerzas
    
      float ax1 = (Ex1+ Bx1)/P1.Masa;
      float ay1 = (Ey1+ By1)/P1.Masa;
      float az1 = Ez1/P1.Masa;

      float ax2 = (Ex2+ Bx2)/P2.Masa;
      float ay2 = (Ey2+ By2)/P2.Masa;
      float az2 = Ez2/P2.Masa;

      // Evolucion temporal

      P1.Pos_evol(ax1,ay1,az1,0.01);
      P2.Pos_evol(ax2,ay2,az2,0.01);
 
      cout << P1.X <<","<< P1.Y <<","<< P1.Z << ","
           << P2.X <<","<< P2.Y <<","<< P2.Z << endl;

    }
  return 0;
}
