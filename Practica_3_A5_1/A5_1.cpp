#include "A5_1.hpp"





A5_1::A5_1(void){
	int Key1 [] = {0,0,0,1,0,1,0,0};
	int Key2 [] = {1,1,0,0,1};
	int Key3 [] = {1,0,1,0,1,1};
	int key_position [] = {3,4,4};
	int LFSR1 [] = {2,4,6};
	int LFSR2 [] = {2,3};
	int LFSR3 [] = {2,4,5};
	
	for (int i = 0; i < 8; ++i)
	{
		Key1_.push_back(Key1[i]);
		//Key1_.insert(Key1_.begin(), Key1[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		Key2_.push_back(Key2[i]);
		//Key2_.insert(Key2_.begin(), Key2[i]);
	}

	for (int i = 0; i < 6; ++i)
	{
		Key3_.push_back(Key3[i]);
		//Key3_.insert(Key3_.begin(), Key3[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		key_position_.push_back(key_position[i]);
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
	/*
	VerKey(Key1_);
	VerKey(Key2_);
	VerKey(Key3_);
	VerKey(LFSR1_);
	VerKey(LFSR2_);
	VerKey(LFSR3_);
	*/
	cout << "Output_"<< endl;
	VerOutput();
}

A5_1::~A5_1(){}

int A5_1::FuncionMayoritaria(void){
	int major;
	int major1 = Key1_[key_position_[0]] * Key2_[key_position_[1]];
	int major2 = Key1_[key_position_[0]] * Key3_[key_position_[2]];
	int major3 = Key2_[key_position_[1]] * Key3_[key_position_[2]];
	major = major1 xor major2 xor major3;
	//cout << Key1_[key_position_[0]] << Key2_[key_position_[1]] << Key3_[key_position_[2]] << endl;
	return major;
}

void A5_1::Desplazamiento(void){
	int algo = FuncionMayoritaria();
	if (algo == Key1_[key_position_[0]])
	{
		//CalcularEntrada(Key1_, LFSR1_);
		Mover(Key1_, CalcularEntrada(Key1_, LFSR1_));
		//cout << "aqui 1" << endl;
	}
	if (algo == Key2_[key_position_[1]]){
		Mover(Key2_, CalcularEntrada(Key2_, LFSR2_));
		//cout << "aqui 2" << endl;
	}
	if (algo == Key3_[key_position_[2]]){
		Mover(Key3_, CalcularEntrada(Key3_, LFSR3_));
		//cout << "aqui 3" << endl;
	}
}

void A5_1::BitEncrypt(void){

	int bit_encrypt = Key1_.back() xor Key2_.back() xor Key3_.back();
	Output_.push_back(bit_encrypt);
	//CalcularEntrada(Key1_, LFSR1_);
	//cout << bit_encrypt << Key1_.back() << Key2_.back() << Key3_.back()<< endl;
}

void A5_1::Encrypt(void){
	int ciclos;
	vector<int> entrada;
	cout << "Ciclos de Reloj: ";
	cin >> ciclos;
	VerKey(Key1_);
	VerKey(Key2_);
	VerKey(Key3_);
	for (int i = 0; i < ciclos; ++i)
	{
		BitEncrypt();
		Desplazamiento();
		cout << "AAAAAAAAAAAAAAAAAAAA" << endl;
		VerKey(Key1_);
		VerKey(Key2_);
		VerKey(Key3_);
		VerOutput();
	}
}

void A5_1::Mover(vector<int>& Key, int entrada){
	Key.pop_back();
	Key.insert(Key.begin(), entrada);
}

int A5_1::CalcularEntrada(vector<int> Key, vector<int> LFSR){
	int entrada = Key[LFSR[0]] xor Key[LFSR[1]];
	//cout << Key[LFSR[0]] << " " << LFSR[0] << " "<< Key[LFSR[1]]<< " " << LFSR[1];
	for (int i = 2; i < LFSR.size(); ++i)
	{
		entrada = entrada xor Key[LFSR[i]];
		//cout << " "<<Key[LFSR[i]] << " "<< LFSR[i];
	}
	//cout << endl;
	cout << entrada << " entrada" << endl;
	return entrada;
}

void A5_1::VerOutput(void){
	for (int i = 0; i < Output_.size(); ++i)
	{
		cout << Output_[i] << " ";
	}
	cout << endl;
}

void A5_1::VerKey(vector<int> Key){
	for (int i = 0; i < Key.size(); ++i)
	{
		cout << Key[i] << " ";
	}
	cout << endl;
}