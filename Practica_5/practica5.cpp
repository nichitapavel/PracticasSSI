#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"

using namespace std;

bool IsPrime(long number){		
	long i;
	
	for (i=2; i<number; i++){
		if (number % i == 0){
			return false;
		}
	}
	
	return true;	
}

unsigned long y(unsigned long x, unsigned long alfa, unsigned long primo){
	unsigned long resultado;
	resultado = pow(alfa, x);
	resultado %= primo;
	return resultado;
}

unsigned long k(unsigned long y, unsigned long x, unsigned long primo){
	unsigned long k;
	k = pow(y, x);
	k %= primo;
	return k;
}

int main()
{
	unsigned long alfa, primo = 4, xa, xb;
	
	while(IsPrime(primo) != true){
		cout << "Dame primo: ";
		cin >> primo;
	}

	alfa = primo; 
	while (alfa >= primo){
		cout << "Dame alfa: ";4
		cin >> alfa;
	}
	cout << "Dame Xa: ";
	cin >> xa;
	cout << "Dame Xb: ";
	cin >> xb;

	unsigned long ya, yb;
	ya = y(xa, alfa, primo);
	yb = y(xb, alfa, primo);
	cout << "Ya = " << ya << endl;
	cout << "Yb = " << yb << endl;

	cout << "K de a = " << k(yb, xa, primo) << endl;
	cout << "K de b = " << k(ya, xb, primo) << endl;

	return 0;
}