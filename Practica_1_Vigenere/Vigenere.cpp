#include "Vigenere.hpp"
#define MOD 26;

Vigenere::Vigenere(string key, string message){
	key_ = key;
	message_ = message;
	alfabet();
}

Vigenere::~Vigenere(){}

int Vigenere::EnteroDeLetra(char letra){
	for (int i = 0; i < alfabet_.size(); ++i)
	{
		if (alfabet_[i] == letra)
		{
			return i;
		}
	}
}

void Vigenere::encrypt(){
	cout << key_ << endl;
	cout << message_ << endl;
	for (int i = 0; i < message_.size(); ++i)
	{
		char letra = EnteroDeLetra(message_[i]);
		encrypted_message_.push_back(letra);
		cout << encrypted_message_[i] << endl; 
	}
	cout << "AAAAAAAAAAAAAAAAAAAa" << endl;
	for (int i = 0; i < key_.size(); ++i)
	{
		char letra = EnteroDeLetra(key_[i]);
		encrypted_key_.push_back(letra);
		cout << encrypted_key_[i] << endl;
	}

	for (int i = 0; i < encrypted_message_.size(); ++i)
	{
		/* code */
	}
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

void Vigenere::alfabet(void){
	//cout << "aaaaaaaaa" << endl;
	for (int i = 0; i < 26; ++i)
	{
		alfabet_.push_back((char)('A' + i));
		//cout << (char)('A' + i) << endl;
	}
	//cout << "bbbbbbbbbbb" << endl;
	for (int i = 0; i < 26; ++i)
	{
		cout << alfabet_[i] << endl;
	}
}
