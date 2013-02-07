#include "Vigenere.hpp"

Vigenere::Vigenere(string key, string message){
	key_ = key;
	message_ = message;
}

Vigenere::~Vigenere(){}

void Vigenere::encrypt(){
	cout << key_ << endl;
	cout << message_ << endl;
	stringtoascii();
}

void Vigenere::stringtoascii(){
	vector<int> key_ascii; 
	for (int i = 0; i < key_.size(); ++i)
	{
		int aux = (int)key_[i];
		cout << aux << endl;
		//key_ascii.push_back(aux);
	}
	
	for (int i = 0; i < key_ascii.size(); ++i)
	{
		cout << key_ascii[i] << endl;
	}
}
