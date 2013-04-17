#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull Exponente(ull a, ull n, ull m){
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

int main(int argc, char const *argv[])
{
	ull a = 1616, p = 1619, m = 2947;
	cout << Exponente(a, p, m) << endl;
	return 0;
}