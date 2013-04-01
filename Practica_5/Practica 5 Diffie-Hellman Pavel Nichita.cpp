/////////////////
//Pavel Nichita//
/////////////////

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"

#define ull unsigned long long

using namespace std;

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

bool IsPrime(ull number){		
	ull i;
	
	for (i=2; i<number; i++){
		if (number % i == 0){
			return false;
		}
	}
	
	return true;	
}

// potencia para numeros pequenos
ull y(ull x, ull alfa, ull primo){
	ull resultado;
	resultado = pow(alfa, x);
	resultado %= primo;
	return resultado;
}

ull k_exponente_modular(ull y, ull x, ull primo){
	ull k;
	k = exponente(y, x, primo);
	return k;
}

ull k_exponente_normal(ull y, ull x, ull primo){
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
	//ya = y(xa, alfa, primo);
	//yb = y(xb, alfa, primo);
	
	ya = exponente(alfa, xa, primo);
	yb = exponente(alfa, xb, primo);
	
	cout << "Ya = " << ya << endl;
	cout << "Yb = " << yb << endl;

	//cout << "K de a = " << k_exponente_normal(yb, xa, primo) << endl;
	//cout << "K de b = " << k_exponente_normal(ya, xb, primo) << endl;

	cout << "K de a = " << k_exponente_modular(yb, xa, primo) << endl;
	cout << "K de b = " << k_exponente_modular(ya, xb, primo) << endl;

	return 0;
}