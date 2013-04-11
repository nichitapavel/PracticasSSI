/////////////////
//Pavel Nichita//
// Fiat Shamir //
/////////////////

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"

#define ull unsigned long long

using namespace std;

void AlfaRango(ull& input, ull N){
  while(input > N or input < 0){
    cout << "Numero no esta dentro del rango [0, N]. Vuelve a Introducir" << endl;
    cout << "Dame numero: ";
    cin >> input;
  }
}

void Euclide(ull& s, ull N){
  ull cociente, resto=1, a= s, b = N;

  if (a<b){
    cociente = a;
    a = b;
    b = cociente;
  }
  
  while (resto>0) {
    cociente = a / b;
    resto = a % b;
    a = b;
    b = resto;
  }
  
  if (a != 1){
    cout << "s no es primo con N, vuelve a introducir" << endl;
    cout << "Dame s: ";
    cin >> s;
    Euclide(s, N);
  }
}

// exponencion modular
ull exponente(ull a, ull n, ull m){
  ull expo = 1;
  ull x = a % m;
  while (n > 0){
  
  if (n%2 == 1)
  {
      expo = (expo * x) % m;
  }
  
  x = (x*x) % m;
  
  n /= 2;

  }
  
  return expo;
}

//Inicializacion con numeros secretos y primos p y q, devuelve N para Peggy y Victor
ull Inicializacion(void){
  ull p, q;
  cout << "Dame p: ";
  cin >> p;
  cout << "Dame q: ";
  cin >> q;

  ull N = p*q;

  return N;
}

//Numero secreto s de Peggy, 0<s<N y maximo divisor comun = 1
ull Numero_S(ull N){
  ull s;

  cout << "Dame s: ";
  cin >> s;
  AlfaRango(s, N);
  Euclide(s, N);

  return s;
}

//Numero publico v de Victor, v = s^2 mod N
ull Numero_V(ull s, ull N){
  ull v;

  //v = (s*s) % N;
  v = exponente(s, 2, N);

  return v;
}

//Peggy elige un compromiso secreto x, 0<x<N
//y calcula a, que se le pasa a Victor
ull Numero_X(ull N){
  ull x;

  cout << "Dame x: ";
  cin >> x;
  AlfaRango(x, N);

  return x;
}

ull Numero_A(ull N, ull x){
  ull a;

  //a = (x*x) % N;
  a = exponente(x, 2, N);

  return a;
}

//Victor elige entre 0 o 1, y envia a Peggy
int Elegir_E(void){
  ull e;

  cout << "Dame e: ";
  cin >> e;

  return e;
}

//Peggy calcula y, y lo envia a Victor
ull Numero_Y(int e, ull x, ull N, ull s){
  ull y;

  if (e == 0)
    y = x % N;
  else
    y = (x*s) % N;

  return y;
}

void Validacion(ull a, ull y, int i){
  if (y == a)
  cout << "Iteracion " << i+1 << " Valida" << endl;
  else
  cout << "Iteracion " << i+1 << " No Valida" << endl;
}

//Victor comprueba que y^2 mod N == a * v^e mod N
void Comprobacion(int e, int i, ull N, ull v, ull a, ull y){
  ull y_2, a_2;

  if (e == 0)
  {
    //y_2 = (y*y) % N;
    y_2 = exponente(y, 2, N);
    a_2 = a % N;
    Validacion(a_2, y_2, i);
  }
  else{
    //y_2 = (y*y) % N;
    y_2 = exponente(y, 2, N);
    a_2 = (a*v) % N;
    Validacion(a_2, y_2, i);
  }
}


int main(int argc, char const *argv[])
{
  int iteraciones;

  //Peggy
  ull s, a, y, x;

  //Victor
  ull v;
  int e;

  //Peggy y Victor
  ull N;

  N = Inicializacion();
  s = Numero_S(N);//A Peggy se le envia s
  v = Numero_V(s, N);//A Victor se le envia v

  cout << "Iteraciones: ";
  cin >> iteraciones;

  cout << "N = " << N << endl;
  cout << "v = " << v << endl;

  for (int i = 0; i < iteraciones; ++i)
  {
    x = Numero_X(N);//Peggy elige "x" y cal-
    a = Numero_A(N, x);// -cula "a" y lo envia a Victor
    e = Elegir_E();//Victor elige entre 0/1 y lo envia a Peggy
    y = Numero_Y(e, x, N, s);//Peggy calcula "y" e lo envia a Victor
    cout << "a = " << a << ", y = " << y << endl;
    Comprobacion(e, i, N, v, a, y);//Victor comprueba que y^2 mod N == a * v^e mod N
  }

  return 0;
}
