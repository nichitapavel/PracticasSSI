#include <string>
#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

class A5_1
{
	vector<int> Key1_;
	vector<int> Key2_;
	vector<int> Key3_;
	vector<int> Output_;
	vector<int> key_position_;
	vector<int> LFSR1_;
	vector<int> LFSR2_;
	vector<int> LFSR3_;


private:
	
public:
	A5_1(void);
	~A5_1(void);
	int FuncionMayoritaria(void);
	void Desplazamiento(void);
	void BitEncrypt(void);
	void Encrypt(void);
	void Mover(vector<int>& Key, int entrada);
	int CalcularEntrada(vector<int> Key, vector<int> LFSR);
	void VerOutput(void);
	void VerKey(vector<int> Key);
};