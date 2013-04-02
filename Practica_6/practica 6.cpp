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

int main(int argc, char const *argv[])
{
	ull p = 7, q = 5, N, s = 3, v, iteraciones = 2, x, e, y;

	/*
	cout << "Dame p: ";
	cin >> p;
	cout << "Dame q: ";
	cin >> q;
	cout << "Dame s: ";
	cin >> s;

	cout << "Dame iteraciones: ";
	cin >> iteraciones;
	*/
	N = p*q;
	v = (s*s) % N;

	cout << "N = " << N << endl;
	cout << "v = " << v << endl;
	for (int i = 0; i < iteraciones; ++i)
	{
		cout << "Dame X: ";
		cin >> x;

		ull a = (x*x) % N;
		cout << a << " AAAA 11111" << endl;

		cout << "Dame e: ";
		cin >> e;
		//int e = rand(0,1);

		if (e == 0)
		{
			y = x % N;
		}
		else{
			y = (x*s) % N;
		}
		
		cout << y << " YYYY 111111" << endl;	

		if (e == 0)
		{
			y *= y;
			cout << y << " YYYY " << endl;
			a %= N;
			cout << a << " AAAA" << endl;
			if (y == a)
			{
				cout << "Iteracion " << i+1 << " Valida" << endl;
			}
			else{
				cout << "Iteracion " << i+1 << " No Valida" << endl;
			}
		}
		else{
			y *= y;
			cout << y << " YYYY" << endl;
			a = (a*v) % N;
			cout << a << " AAAA" << endl;
			if (y == a)
			{
				cout << "Iteracion " << i+1 << " Valida" << endl;
			}
			else{
				cout << "Iteracion " << i+1 << " No Valida" << endl;
			}
		}
	}


	return 0;
}