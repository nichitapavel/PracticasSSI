#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"

#define ull unsigned long long

using namespace std;

bool IsPrime(ull number){		
	ull i;
	
	for (i=2; i<number; i++){
		if (number % i == 0){
			return false;
		}
	}
	
	return true;	
}

ull y(ull x, ull alfa, ull primo){
	ull resultado;
	resultado = pow(alfa, x);
	resultado %= primo;
	return resultado;
}

ull k(ull y, ull x, ull primo){
	ull k;
	k = pow(y, x);
	k %= primo;
	return k;
}

int main()
{
	ull alfa, primo = 4, xa, xb;
	
	while(IsPrime(primo) != true){
		cout << "Dame primo: ";
		cin >> primo;
	}

	alfa = primo; 
	while (alfa >= primo){
		cout << "Dame alfa: ";
		cin >> alfa;
	}
	cout << "Dame Xa: ";
	cin >> xa;
	cout << "Dame Xb: ";
	cin >> xb;

	ull ya, yb;
	ya = y(xa, alfa, primo);
	yb = y(xb, alfa, primo);
	cout << "Ya = " << ya << endl;
	cout << "Yb = " << yb << endl;

	cout << "K de a = " << k(yb, xa, primo) << endl;
	cout << "K de b = " << k(ya, xb, primo) << endl;

	return 0;
}