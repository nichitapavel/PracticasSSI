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
	cout << "Tamano Mensaje: " << message_.size() << endl;
	for (int i = 0; i < message_.size(); ++i)
	{
		char letra = EnteroDeLetra(message_[i]);
		encrypted_message_.push_back(letra); 
	}
	for (int i = 0; i < key_.size(); ++i)
	{
		char letra = EnteroDeLetra(key_[i]);
		encrypted_key_.push_back(letra);
	}
	for (int i = 0; i < encrypted_message_.size(); ++i)
	{
		int j = i % encrypted_key_.size();
		encrypted_message_[i] += encrypted_key_[j];
		if (encrypted_message_[i] >= 26)
		{
			encrypted_message_[i] %= 26;
		}
	}
	for (int i = 0; i < encrypted_message_.size(); ++i)
	{
		int valorletra = encrypted_message_[i];
		char letra_output = alfabet_[valorletra];
		encrypted_message_output_.push_back(letra_output);
	}
}

void Vigenere::stringtoascii(){
	/*
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
	*/
}

void Vigenere::alfabet(void){
	//cout << "aaaaaaaaa" << endl;
	for (int i = 0; i < 26; ++i)
	{
		alfabet_.push_back((char)('A' + i));
	}
}

void Vigenere::showencription(void){
	cout << "Cadena Encriptada: " << encrypted_message_output_ << endl;
	cout << "Tamano Cadena: " << encrypted_message_output_.size() << endl;
};