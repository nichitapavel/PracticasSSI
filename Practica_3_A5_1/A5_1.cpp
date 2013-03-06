#include "A5_1.hpp"

/*
-------------------------------------------------------
----------------------- PRIVATE -----------------------
-------------------------------------------------------
*/

//Los datos de entrada por defecto
void A5_1::DefaultInput(void){
	
	int Key1 [] = {1,0,0,0, 1,0,1,1,0,0,0,1,0,0,0,1,0,0,1};
	int Key2 [] = {0,1,0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,1,1,0,1,0};
	int Key3 [] = {1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,0,0,1,1,1,1,0,1};
	int clocking_bits [] = {8,10,10};
	int LFSR1 [] = {18,17,16,13,0};
	int LFSR2 [] = {21,20,0};
	int LFSR3 [] = {22,21,20,7,0};
	
	/*
	int Key1 [] = {1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1};
	int Key2 [] = {0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0};
	int Key3 [] = {1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1};
	int clocking_bits [] = {8,10,10};
	int LFSR1 [] = {18,17,16,13,0};
	int LFSR2 [] = {21,20,0};
	int LFSR3 [] = {22,21,20,7,0};
	*/
	for (int i = 0; i < 19; ++i)
	{
		Key1_.push_back(Key1[i]);
	}

	for (int i = 0; i < 22; ++i)
	{
		Key2_.push_back(Key2[i]);
	}

	for (int i = 0; i < 23; ++i)
	{
		Key3_.push_back(Key3[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		clocking_bits_.push_back(clocking_bits[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		LFSR1_.push_back(LFSR1[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		LFSR2_.push_back(LFSR2[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		LFSR3_.push_back(LFSR3[i]);
	}
};

//Metodo para obtener los datos de entrada al ejecutar el programa
//es solo un modelo, con ello se obtiene los datos de los vectores de clave
vector<int> A5_1::GetInputKey(void){
	string input;
	vector<int> output;
	cout << " ";
	cin >> input;
	for (int i = 0; i < input.size(); i++ )
	{
		output.push_back((int) input[i]-48);
	}
	return output;
};

//obtener los polinomios
vector<int> A5_1::GetInputLFSR(void){
	int indice = 1, integer;
	vector<int> input;
	cout << "Elemento " << indice << ": ";
	cin >> integer;
	while (integer != -1){
		input.push_back(integer);
		indice++;
		cout << "Elemento " << indice << ": ";
		cin >> integer;
	}
	return input;
}

//obtener los bits de reloj
vector<int> A5_1::GetInputClockingBits(void){
	vector<int> input;
	int clock_bit;
	for (int i = 0; i < 3; ++i)
	{
		cout << "Clocking Bit " << i+1 << " :";
		cin >> clock_bit;
		input.push_back(clock_bit);
	}
	return input;
};

//Si se meten los datos por teclado se llama esta funcion para
//cambiar los polinomios a posiciones de vectores
//ej: x^19 + x^4 => 18, 3
void A5_1::ReSetLFSR(vector<int>& input){
	for (int i = 0; i < input.size(); ++i)
	{
		input[i] -= 1;
	}
};

//metodo contenedor para obtener los datos por teclado
void A5_1::GetNewInput(void){
	cout << "Key 1:";
	Key1_ = GetInputKey();
	cout << "LFSR 1 (-1 para acabar)" << endl;
	LFSR1_ = GetInputLFSR();
	ReSetLFSR(LFSR1_);
	cout << "Key 2:";
	Key2_ = GetInputKey();
	cout << "LFSR 2 (-1 para acabar)" << endl;
	LFSR2_ = GetInputLFSR();
	ReSetLFSR(LFSR2_);
	cout << "Key 3:";
	Key3_ = GetInputKey();
	cout << "LFSR 3 (-1 para acabar)" << endl;
	LFSR3_ = GetInputLFSR();
	ReSetLFSR(LFSR3_);
	cout << "Ciclos de reloj" << endl;
	clocking_bits_ = GetInputClockingBits();
};

//funcion que calcula el bit que se utilizara para cifrar
void A5_1::BitEncrypt(void){

	int bit_encrypt = Key1_.back() xor Key2_.back() xor Key3_.back();
	Output_.push_back(bit_encrypt);
};

//funcion que obtiene el bit mayoritario para ver que vector se mueve
int A5_1::MajorityRule(void){
	int major_bit;
	int major_bit_1 = Key1_[clocking_bits_[0]] * Key2_[clocking_bits_[1]];
	int major_bit_2 = Key1_[clocking_bits_[0]] * Key3_[clocking_bits_[2]];
	int major_bit_3 = Key2_[clocking_bits_[1]] * Key3_[clocking_bits_[2]];
	major_bit = major_bit_1 xor major_bit_2 xor major_bit_3;
	return major_bit;
};

//funcion que calcula el bit de entrada en el vector que se mueve
int A5_1::CalculateEntryBit(vector<int> Key, vector<int> LFSR){
	int entrada = Key[LFSR[0]] xor Key[LFSR[1]];
	for (int i = 2; i < LFSR.size(); ++i)
	{
		entrada = entrada xor Key[LFSR[i]];
	}
	return entrada;
};

//funciona que mueve un vector y introduce el nuevo bit
void A5_1::MoveKeyVector(vector<int>& Key, int input){
	Key.pop_back();
	Key.insert(Key.begin(), input);
};

//contenedor para mover los vectores
void A5_1::MoveContainer(void){
	int major_bit = MajorityRule();
	if (major_bit == Key1_[clocking_bits_[0]])
	{
		MoveKeyVector(Key1_, CalculateEntryBit(Key1_, LFSR1_));
	}
	if (major_bit == Key2_[clocking_bits_[1]]){
		MoveKeyVector(Key2_, CalculateEntryBit(Key2_, LFSR2_));
	}
	if (major_bit == Key3_[clocking_bits_[2]]){
		MoveKeyVector(Key3_, CalculateEntryBit(Key3_, LFSR3_));
	}
};

//ver la secuencia "cifrada"
void A5_1::Output(void){
	for (int i = 0; i < Output_.size(); ++i)
	{
		cout << Output_[i] << " ";
	}
	cout << endl;
};

/*
-------------------------------------------------------
----------------------- PUBLIC ------------------------
-------------------------------------------------------
*/

//Constructor
A5_1::A5_1(void){
	DefaultInput();
	//GetNewInput();
};

//Destructor
A5_1::~A5_1(){};

//Contenedor del cifrado
void A5_1::Encrypt(void){
	int ciclos;
	vector<int> entrada;
	cout << "Ciclos de Reloj: ";
	cin >> ciclos;
	for (int i = 0; i < ciclos; ++i)
	{
		BitEncrypt();
		MoveContainer();
	}
	Output();
};