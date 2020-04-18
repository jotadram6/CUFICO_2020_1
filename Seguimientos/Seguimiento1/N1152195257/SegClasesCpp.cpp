#include <math.h>
#include <fstream>
#include <iostream>
using namespace std;

double k = 10; //Constante de Coulomb

//////////////////////////////////////////////////
////////Definicion de clases y estructuras////////
//////////////////////////////////////////////////

class particle
{
public:
  
  //Variables//
  
  int charge;
  double mass;
  double x, y, z;
  double vx, vy, vz;
  double ax, ay, az;
  
  //Funciones//
  
  void setvalues(double X, double Y, double Z,
		 double VX, double VY, double VZ,
		 double AX, double AY, double AZ,
		 double m, int q)
  {
    x = X;
    y = Y;
    z = Z;
    vx = VX;
    vy = VY;
    vz = VZ;
    ax = AX;
    ay = AY;
    az = AZ;
    mass = m;
    charge = q;
  }

  void pos_evol(double t)
  {
    x = x + (vx*t) + (0.5*ax*(t*t));
    vx = vx + ax*t;
    y = y + (vy*t) + (0.5*ay*(t*t));
    vy = vy + ay*t;
    z = z + (vz*t) + (0.5*az*(t*t));
    vz = vz + az*t;
  }
};

struct Electric_field
{
  double x;
  double y;
  double z;
};

struct Magnetic_field
{
  double x;
  double y;
  double z;
};

struct Lorentz_force
{
  double x;
  double y;
  double z;
};

///////////////////////////////////////
////////Definicion de funciones////////
///////////////////////////////////////

Electric_field E_field(particle A, particle B)
  {
    //Campo electrico generado por la particula A en la posicion de B
    double r = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z));
    double rho = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
    double sin_theta = rho/r;
    double cos_theta = (B.z-A.z)/r;
    double sin_phi = (B.y-A.y)/rho;
    double cos_phi = (B.x-A.x)/rho;
    Electric_field E;
    double EE = k/(r*r);
    E.x = A.charge*EE*sin_theta*cos_phi;
    E.y = A.charge*EE*sin_theta*sin_phi;
    E.z = A.charge*EE*cos_theta;
    return E;
  }

/////////////////////////////////
////////Funcion principal////////
/////////////////////////////////

int main()
{
  Magnetic_field B;
  particle  par1, par2;
  Lorentz_force F1, F2;
  
  //Se definen las condiciones iniciales//
  B.x = 0.0; B.y = 0.0; B.z = 10.0;
  par1.setvalues(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 1);
  par2.setvalues(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, -1);

  //Se crea un archivo para guardar datos de las posiciones de las particulas//
  ofstream archivo;
  archivo.open("datos.txt", ios::out);//Se abre el archivo
  if (archivo.fail())
    {
      exit(1);
    }
  
  for (int i=0; i<10000; i++)
    {
      //Fuerza de Lorentz sobre la particula 1
      F1.x = par1.charge*(E_field(par2,par1).x + par1.vy*B.z - par1.vz*B.y);
      F1.y = par1.charge*(E_field(par2,par1).y + par1.vz*B.x - par1.vx*B.z);
      F1.z = par1.charge*(E_field(par2,par1).z + par1.vx*B.y - par1.vy*B.x);
      //Se actualizan las aceleraciones de la particula 1
      par1.ax = F1.x/par1.mass;
      par1.ay = F1.y/par1.mass;
      par1.az = F1.z/par1.mass;

      //Fuerza de Lorentz sobre la particula 2
      F2.x = par2.charge*(E_field(par1,par2).x + par2.vy*B.z - par2.vz*B.y);
      F2.y = par2.charge*(E_field(par1,par2).y + par2.vz*B.x - par2.vx*B.z);
      F2.z = par2.charge*(E_field(par1,par2).z + par2.vx*B.y - par2.vy*B.x);
      //Se actualizan las aceleraciones de la particula 2
      par2.ax = F2.x/par2.mass;
      par2.ay = F2.y/par2.mass;
      par2.az = F2.z/par2.mass;      

      //Se actualizan las posiciones y velocidades
      par1.pos_evol(0.01);
      par2.pos_evol(0.01);

      cout << par1.x <<" "<< par1.y <<" "<< par1.z <<
	" "<< par2.x <<" "<< par2.y <<" "<< par2.z << endl;

      archivo << par1.x <<" "<< par1.y <<" "<< par1.z <<
	" "<< par2.x <<" "<< par2.y <<" "<< par2.z << endl;
    }

  archivo.close();//Se cierra el archivo
  
  return 0;
}
