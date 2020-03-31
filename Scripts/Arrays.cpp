#include <iostream>
#include <vector>

using namespace std;

int SumUp(std::vector <int> x)
{
  int a=0;
  for (int i=0; i<x.size(); i++)
    {
      a+=x[i];
    }
  return a;
}

int SumUp(int x[])
{
  int a=0;
  for (int i=0; i<3; i++)
    {
      a+=x[i];
    }
  return a;
}

class Particle
{
public:
  float x,y,z;
};

int main()
{
  int x[]={1,2,3};
  cout << x[2] << endl;
  std::vector <int> h;
  cout << h.size() << endl;
  h.push_back(2);
  cout << h.size() << endl;
  cout << h[0] << endl;
  cout << h.at(0) << endl;
  h.push_back(4);
  h.push_back(5);
  cout << h.front() << endl;
  cout << h.back() << endl;
  cout << SumUp(h) << endl;
  cout << SumUp(x) << endl;

  //Array of classes
  Particle Combo[3];
  Combo[1].x=10.5;
  cout << "Arreglos de clases" << endl;
  cout << Combo[0].y << endl;
  cout << Combo[1].x << endl;

  std::vector <Particle> MeroCombo;
  Particle P1;
  P1.x=10.5;
  MeroCombo.push_back(P1);
  cout << "Vector de clases" << endl;
  cout << MeroCombo[0].x << endl;
  
  return 0;
}
