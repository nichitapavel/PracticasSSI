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
	ull p = 683, q = 811, N, s = 43215, v, iteraciones = 1, x, e, y;

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
		
		cout << "Dame e: ";
		cin >> e;
		//int e = rand(0,1);

		cout << a << " A" << endl;
		if (e == 0)
		{
			y = x % N;
			cout << y << " Y" << endl;
		}
		else{
			y = (x*s) % N;
			cout << y << " Y" << endl;	
		}
		
		

		if (e == 0)
		{
			y *= y;
			y %= N;
			a %= N;
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
			y %= N;
			a = (a*v) % N;
			cout << y << " y*y mod N" << endl;
			cout << a << " a*v mod N" << endl;
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