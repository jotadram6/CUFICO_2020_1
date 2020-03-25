#include <iostream>

using namespace std;

int main()
{
  float x = 10.5;

  // & este operador lo llamados operador "direccion de"
  
  cout << x << "y su direccion de memoria " << &x << endl;

  // * este operador lo llamados operador "dereferencia"
  // es decir si con el operaor direccion de obtenemos una referencia al espacio de memoria de una variable con el operador dereferencia obtenemos el valor que esta guardado en un espacio de memoria
  // * nos apunta a un espacio de memoria -> Puntero

  int a=1, b=2;
  int * p; //nuestro primer puntero
  
  cout << a << " " << b << " " << p << " " << &a << " " << &b << " " << &p << endl;

  p=&a;
  
  cout << a << " " << b << " " << p << " " << &a << " " << &b << " " << &p << endl;

  *p=10;

  cout << a << " " << b << " " << p << " " << &a << " " << &b << " " << &p << endl;

  p=&b;
  
  cout << a << " " << b << " " << p << " " << &a << " " << &b << " " << &p << endl;

  *p=20;

  cout << a << " " << b << " " << p << " " << &a << " " << &b << " " << &p << endl;

  //Ejercicio mas complejo

  int jj = 3, kk=4;
  int * p1, * p2;

  cout << "Initial" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;

  p1=&jj;
  p2=&kk;
  
  cout << "Second" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;

  *p1=10;

  cout << "Third" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;

  *p2=*p1;

  cout << "Fourth" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;
  
  p1=p2;

  cout << "Third" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;
  
  *p1=20;

  cout << "Fifth" << endl;
  cout << "jj=" << jj << " kk=" << kk  << " p1=" << p1  << " p2=" << p2 << endl;
  cout << "&jj=" << &jj << " &kk=" << &kk  << " &p1=" << &p1  << " &p2=" << &p2 << endl;

  
  return 0;
}

