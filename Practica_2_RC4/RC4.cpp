#include "RC4.hpp"

/*
---------------------- PRIVATE METHODS ----------------------
*/

/*---------------- --- ----------------*/
/*---------------- KSA ----------------*/
/*---------------- --- ----------------*/

// Inicializamos el vector S y K, con sus respectivos valores
void RC4::KSAInitialization(){
	int key_size = key_.size();
	for (int i = 0; i < KEYSIZE; ++i)
	{
		S.push_back(i);
		K.push_back(key_[i % key_size]);
	}
}

// Hacemos la permutacion sobre S
void RC4::KSAPermutation(){
	int j = 0;
	for (int i = 0; i < KEYSIZE; ++i)
	{
		j = (j + S[i] + K[i]) % KEYSIZE;
		swap(S[i], S[j]);
	}
}

// Llamada a KSA para completar el primer paso
void RC4::KSA(void){
	KSAInitialization();
	KSAPermutation();
}

/*---------------- --- ----------------*/
/*---------------- PGRA ----------------*/
/*---------------- --- ----------------*/

// Calculamos el decimal en binario y lo guardamos en un vector de enteros
void RC4::PGRACalculateMod(vector<int>& binary_in_reverse, int integer){
	while (integer != 0){
		binary_in_reverse.push_back(integer % 2);
		integer = integer / 2;
	}
}

// Si una vez pasado a binario, no se completo el vector de bits
// hasta los 16 bits, completamos el vector con 0
void RC4::PGRACompleteByte(vector<int>& binary){
	if (binary.size() <= 16){
		while (binary.size() < 16){
			binary.push_back(0);
		}
	}
}

// Corregimos el vector de bits, hasta ahora estaba al reves
void RC4::PGRACorrectBinary(vector<int> input, vector<int>& output){
	for (int i = input.size() - 1; i > -1; --i)
	{	
		output.push_back(input[i]);
	}
}

// Sacamos por pantalla el vectorlos bits
void RC4::PGRABinaryOutput(vector<int> binary){
	for (int i = 0; i < binary.size(); ++i)
	{
		cout << binary[i];
		if (i % 4 == 3){
			cout << " ";
		}
	}
	cout << endl;
}

// El metodo que encapsula todo el proceso de cambio a binario
void RC4::PGRADecimalToBinary(int decimal){
	vector<int> binary_in_reverse;
	vector<int> binary;
	int intdecimal = decimal;
	
	PGRACalculateMod(binary_in_reverse, intdecimal);
	PGRACompleteByte(binary_in_reverse);	
	PGRACorrectBinary(binary_in_reverse, binary);
	cout << intdecimal << " ";
	PGRABinaryOutput(binary);
}

// El cifrado del mensaje
void RC4::PRGA(){
	int k = 0, j = 0, t;
	for (int i = 0; i < message_.size(); ++i)
	{
		k = (k + 1) % KEYSIZE;
		j = (j + S[k]) % KEYSIZE;
		swap(S[k], S[j]);
		t = (S[k] + S[j]) % KEYSIZE;
		C.push_back(S[t] + message_[i]);
		
		PGRADecimalToBinary(S[t]);
		PGRADecimalToBinary(message_[i]);
		PGRADecimalToBinary(C[i]);
		cout << endl;
	}
}

/*
---------------------- PUBLIC METHODS ----------------------
*/

// Constructor que inicializa los atributos key_ y message_
RC4::RC4(vector<int> key, vector<int> message){
	key_ = key;
	message_ = message;
};

// Destructor
RC4::~RC4(){};

// Metodo que encapsula todos los pasos de cifrado RC4
void RC4::Encrypt(){
	KSA();
	PRGA();
}
