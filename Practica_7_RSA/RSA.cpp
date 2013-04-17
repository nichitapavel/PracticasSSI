/////////////////
//Pavel Nichita//
/////////////////

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "stdlib.h"
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull Exponente(ull a, ull p, ull m);

//si retorno TRUE puede ser primo, si retorna FALSE no es primo
bool LehmanPeraltaNoDivisible(ull numero){
	ull primos_pequenos [] = {2,3,5,7,11};
	
	for (int i = 0; i < sizeof(primos_pequenos)/sizeof(ull); ++i)
	{
		if (numero % primos_pequenos[i] == 0){
			return false;
		}
	}

	return true;
}

//funcion que llena un victor con 100 numeros aleatorios entre 1 y p-1
vector<ull> LehmanPeraltaRandom100(ull p){
	vector<ull> array;
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		array.push_back((random() % (p-1))+1);
	}

	return array;
}

vector<ull> LehmanPeraltaCalculoY(vector<ull> array_aleatorio, ull p){
	vector<ull> array_y;
	ull mitad_p = (p-1)/2;
	for (int i = 0; i < 100; ++i)
	{
		array_y.push_back(Exponente(array_aleatorio[i], mitad_p, p));
	}
	return array_y;
}

//Control del paso A de LehPer, para los 100 numeros del array, comprobar [a^((p-1)/2) mod p] == 1
//si el resultado de todo ai, el numero no es primo
//si existe al menos un ai distinto de 1 se pasa a siguiente paso
//retorno FALSE si encuentra al menos un numero que no cumple [a^((p-1)/2) mod p] == 1
bool LehmanPeraltaPasoA(vector<ull> array_aleatorio, vector<ull> array_y, ull p){
	for (int i = 0; i < 100; ++i)
	{
		if (array_aleatorio[i] != array_y[i])
		{
			return false;
		}
	}
	return true;
}

//Control paso B de LehPer, para los 100 numeros del array, comprobar que estan dentro del rango (1, p-1)
//retorna FALSE si encuentra un numero que esta fuera del rango
bool LehmanPeraltaPasoB(vector<ull> array_y, ull p){
	for (int i = 0; i < 100; ++i)
	{
		if (array_y[i] < 1 or array_y[i] > p-1)
		{
			return false;
		}
	}
	return true;
}
	
//Control paso C de LehPer, primer paso B tiene que devolver TRUE
//si hay al menos un numero que es igual a p-1, entonces p es primo
//devuelve TRUE si p es primo
bool LehmanPeraltaPasoC(vector<ull> array_y, ull p){
	for (int i = 0; i < 100; ++i)
	{
		if (array_y[i] == p-1)
		{
			return true;
		}
	}
	return false;
}

ull Exponente(ull a, ull p, ull m){
	ull expo = 1;
	ull x = a % m;
	while (p > 0){
		if (p % 2 == 1)
		{
			expo = (expo * x) % m;
		}
		x = (x*x) % m;
		p /= 2;
	}
	return expo;
}

//Contenedor de todo el algoritmo de Lehman Peralta
//Devuelve TRUE si numero p es primo
bool LehmanPeraltaContenedor(ull p){
	vector<ull> array_aleatorio, array_y;
	
	if (p == 2 or p == 3 or p == 5 or p == 7 or p == 11)
	{
		return true;
	}

	if (LehmanPeraltaNoDivisible(p) == true)
	{
		array_aleatorio = LehmanPeraltaRandom100(p);
		array_y = LehmanPeraltaCalculoY(array_aleatorio, p);
		if (LehmanPeraltaPasoA(array_aleatorio, array_y, p) == false)
		{
			if (LehmanPeraltaPasoB(array_y, p) == true)
			{
				return LehmanPeraltaPasoC(array_y, p);
			}
		}
	} 
	
	return false;
}

void EuclidesExtendido(ull f_n, ull d, ull& inverso, ull& exponente_modular){
	ull a = f_n, b = d, modulo = 1, a_2 = f_n;
	long long unidad_negativa = -1, z3, z1 = 0, z2 = 1;
	
	
	if (b > a)
	{
		swap(a,b);
		a_2 = a;
	}

	while (modulo > 0){
		modulo = a % b;
		if (modulo != 0)
		{
			//cout << a << " a b " << b << endl;
			z3 = -1*(a/b)*z2 + z1;
			//cout << z3 << " z3" << endl;
			a = b;
			b = modulo;
			//cout << z1 << " z1 z2 " << z2 << endl;
			z1 = z2;
			z2 = z3;
		}
	}

	if (z3 < 0)
	{
		z3 += a_2;
	}
	//cout << "Resultado final: " << "Inverso: " << z3 << " mcd(): " << modulo << endl;
	inverso = (ull)(z3);
	exponente_modular = (ull)(b);
	//cout << "Resultado final: " << "Inverso: " << inverso << " mcd(): " << exponente_modular << endl;
	cout << "E: " << inverso << endl;
}

string GetMessage(void){
 	// declaraciones iniciales, el espacio blanco que se utilizara para cazar
 	// i guardamos la posicion del espacio en blanco
 	// message se guarda el mensaje sin espacios
 	char space = ' ';
 	int i;
 	string message;
 	
 	// el usuario introduce el mensaje y lo guardamos en message con espacios
 	cout << "Message: ";
 	//cin.get();
 	getline(cin, message);
 	
 	//cout << message << endl;
 	// se obtiene la posicion del primer espacio blanco encontrado
 	i = message.find(space);

 	//cout << i << endl;
 	// si no se encuentra espacion en blanco se devuelve -1
 	// hasat que encuentra espacio blanco en
 	while (i != -1){
 		//borras el espacio de la posicion i y
 		// como es solo un caracter, tamaño 1
 		message.erase(i, 1);
 		// se vuelve a buscar el siguiente espacio
 		i = message.find(space);
 	}

 	// pasar a UPPERCASE si es necesario
 	transform(message.begin(), message.end(), message.begin(), ::toupper);

 	// se devuelve el mensaje sin espacios
 	return message;
};

vector<ull> RSACifrar(string mensaje, ull e, ull n){
	vector<ull> mensaje_cifrado;
	ull mensaje_base_100, caracter_en_base100;

	for (int i = 0; i < mensaje.size(); i+=4)
	{
		mensaje_base_100 = 0;
		for (int j = 0; j < 4; ++j)
		{
			caracter_en_base100 = (ull)(mensaje[i+j])-65;
			mensaje_base_100 += caracter_en_base100*pow(100, 3-j);
			//cout << mensaje_base_100 << endl;
		}
		//cout << endl;
		//cout << Exponente(mensaje_base_100, e, n) << endl;
		mensaje_cifrado.push_back(Exponente(mensaje_base_100, e, n));
	}
	
	return  mensaje_cifrado;
}

void VerMensajeCifrado(vector<ull> mensaje_cifrado){
	for (int i = 0; i < mensaje_cifrado.size(); ++i)
	{
		cout << mensaje_cifrado[i] << " ";
	}
	cout << endl;
}

void RSADescifrar(vector<ull> mensaje_cifrado, ull d, ull n){
	vector<ull> mensaje_descifrado;
	for (int i = 0; i < mensaje_cifrado.size(); ++i)
	{
		mensaje_descifrado.push_back(Exponente(mensaje_cifrado[i], d, n));
	}
	VerMensajeCifrado(mensaje_descifrado);
}

int main(int argc, char const *argv[])
{
	
	ull p = 421, q = 7, n = p*q, f_n = (p-1) * (q-1), d = 1619;
	string mensaje = "MANDADINEROS";
	//ull p = 12347, q = 92347, n = p*q, f_n = (p-1) * (q-1), d = 5;	
	//string mensaje = "AMIGOMIO";
	/*
	ull p_2 = 885320963;
	ull p_3 = 61;
	ull p_4 = 53;
	ull p_5 = 421;
	ull p_6 = 2;
	ull p_7 = 12347;
	ull p_8 = 92347;
	ull p_9 = 24;
	ull p_10 = 3;
	ull p_11 = 5;
	ull p_12 = 7;
	ull p_13 = 11;

	
	bool p_es_primo = LehmanPeraltaContenedor(p);
	cout << p_es_primo << endl;
	
	cout << "P2: " << LehmanPeraltaContenedor(p_2) << endl;
	
	cout << "P3: " << LehmanPeraltaContenedor(p_3) << endl;
	cout << "P4: " << LehmanPeraltaContenedor(p_4) << endl;
	cout << "P5: " << LehmanPeraltaContenedor(p_5) << endl;
	cout << "P6: " << LehmanPeraltaContenedor(p_6) << endl;
	cout << "P7: " << LehmanPeraltaContenedor(p_7) << endl;
	cout << "P8: " << LehmanPeraltaContenedor(p_8) << endl;
	cout << "P9: " << LehmanPeraltaContenedor(p_9) << endl;
	cout << "P10: " << LehmanPeraltaContenedor(p_10) << endl;
	cout << "P11: " << LehmanPeraltaContenedor(p_11) << endl;
	cout << "P12: " << LehmanPeraltaContenedor(p_12) << endl;
	cout << "P13: " << LehmanPeraltaContenedor(p_13) << endl;
	*/

	//ull peta = 885320963, qutoa = 238855417, d = 1164402471153538991;
	//ull a = 19, fn = 12;
	//ull exponente_modular_1, inverso_1, f_n = (peta-1) * (qutoa-1);
	//ull a_2 = 2753, fn_2 = 3120;
	//ull a_3 = 2753, fn_3 = 3120;
	//ull a_5 = 421;
	
	ull inverso, exponente_modular;
	cout << "P: " << p << endl;
	cout << "Q: " << q << endl;
	cout << "D: " << d << endl;
	cout << "N: " << n << endl;
	cout << "F(n): " << f_n << endl;
	cout << mensaje << endl;


	EuclidesExtendido(d, f_n, inverso, exponente_modular);

	//string mensaje = GetMessage();

	vector<ull> mensaje_cifrado = RSACifrar(mensaje, inverso, n);

	VerMensajeCifrado(mensaje_cifrado);

	RSADescifrar(mensaje_cifrado, d, n);	
	return 0;
}