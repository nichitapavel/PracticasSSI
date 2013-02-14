#include <string>
#include <iostream>
#include <vector>
#include "stdlib.h"

// MOD es el tamaño del alfabeto, es una constante que no cambia
#define MOD 26

using namespace std;

class Vigenere
{
	string key_;
	// un string que contiene la clave en original
	string message_;
	// un string que contiene el mensaje en original
	string encrypted_message_output_;
	//un string que contiene el mensaje encriptado
	vector<int> alfabet_message_;
	// un vector de tipo entero que contiene el mensaje pasado
	// a valores equivalentes de enteros
	// del alfabeto, ejemplo: la Letra A del mensaje tendra valor 0
	vector<int> alfabet_key_;
	// un vector de tipo entero que contiene la clave pasada
	// a valores equivalentes de enteros
	// del alfabeto, ejemplo: la Letra A del mensaje tendra valor 0
	vector<char> alfabet_;
	// vector de caracteres que contiene el alfabeto
	// de aqui se extrae el valor de cada letra

private:
	void Alfabet(void);
	// Metodo que populiza el vector de letras
	int IntegerOfLetter(char letter);
	// Metodo que retorna el valor entero de la letra que se le pasa
	// el valor retornado es la posicion de la letra en el vector
	void StringToInteger(string input, vector<int>& output);
	// Metodo que recibe una cadena de caracteres como parametro y la pasa
	// a su equivalente de un vector de enteros
	// el vector de enteros tambien se pasa como parametro, en el es 
	// donde se guarda el nuevo vector de enteros
	// PORQUE? porque el mensaje y la clave tienen que pasar
	// por esta transformacion
	void EncryptMessage(void);
	// Metodo que coge los vectores de enteros del mensaje y clave
	// y hace los calculos necesarios para obtener el mensaje encryptado
	// el mensaje encryptado se guarda en 

public:
	Vigenere(string key, string message);
	// Constructor que recibe 2 parametros, la clave y el mensaje
	~Vigenere(void);
	// Destructor
	void Encrypt(void);
	// Metodo al que se le llama para encriptar el mensaje
	void UnEncrypt(void);
	// Metodo al que se le llama para desencriptar el mensaje
};