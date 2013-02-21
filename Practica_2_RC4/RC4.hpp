#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "stdlib.h"
#include <sstream>
#include <bitset>
#include <limits>

// KEYSIZE es el tamaño del vector S, es una constante que no cambia
#define KEYSIZE 256

using namespace std;

class RC4
{
	vector<int> key_;
	// un vector que contiene la clave en original
	vector<int> message_;
	// un vector que contiene el mensaje en original
	vector<int> S;
	vector<int> K;
	vector<int> C;


private:
	void KSAInitialization(void);
	void KSAPermutation(void);
	void KSA(void);
	
	void PGRACompleteByte(vector<int>& binary);
	void PGRADecimalToBinary(int decimal);
	void PGRABinaryOutput(vector<int> binary);
	void PGRACalculateMod(vector<int>& binary_in_reverse, int integer);
	void PGRACorrectBinary(vector<int> binary_in_reverse, vector<int>& binary);
	void PRGA(void);
public:
	RC4(vector<int> key, vector<int> message);
	~RC4(void);
	void Encrypt(void);
};