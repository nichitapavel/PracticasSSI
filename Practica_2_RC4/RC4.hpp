#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "stdlib.h"
#include <sstream>

// MOD es el tamaño del alfabeto, es una constante que no cambia
#define MOD 26

using namespace std;

class RC4
{
	vector<int> key_;
	// un string que contiene la clave en original
	vector<int> message_;
	// un string que contiene el mensaje en original
	vector<int> S;
	vector<int> K;
	vector<int> C;


private:
	void Initialization(void);
	void View(void);
	
public:
	RC4(vector<int> key, vector<int> message);
	// Constructor que recibe 2 parametros, la clave y el mensaje
	~RC4(void);
	// Destructor
	
	void ViewPosition(int j);
	void ViewC(void);
	void PRGA(void);
};