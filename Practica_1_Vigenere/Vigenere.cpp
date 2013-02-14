#include "Vigenere.hpp"
#define MOD 26;

Vigenere::Vigenere(string key, string message){
	key_ = key;
	message_ = message;
	Alfabet();
};

Vigenere::~Vigenere(){};

int Vigenere::IntegerOfLetter(char letter){
	for (int i = 0; i < alfabet_.size(); ++i)
	{
		if (alfabet_[i] == letter)
		{
			return i;
		}
	}
};

void Vigenere::Encrypt(){	
	StringToInteger(key_, alfabet_key_);
	StringToInteger(message_, alfabet_message_);
	
	EncryptMessage();

	cout << "Encrypted Message: " << encrypted_message_output_ << endl;
	cout << endl;
};

void Vigenere::Alfabet(void){
	for (int i = 0; i < 26; ++i)
	{
		alfabet_.push_back((char)('A' + i));
	}
};

void Vigenere::UnEncrypt(void){
	string unencrypted_message_output_;
	for (int i = 0; i < alfabet_message_.size(); ++i)
	{
		int j = i % alfabet_key_.size();
		int value_of_letter = alfabet_message_[i] - alfabet_key_[j];

		if (value_of_letter < 0)
		{
			value_of_letter += 26;
		}
		char letter = alfabet_[value_of_letter];
		unencrypted_message_output_.push_back(letter);
	}

	cout << "Uncrypted Message: " << unencrypted_message_output_ << endl;
	cout << endl;
};


void Vigenere::StringToInteger(string message, vector<int>& output){
	for (int i = 0; i < message.size(); ++i)
	{
		char letter = IntegerOfLetter(message[i]);
		output.push_back(letter); 
	}
};

void Vigenere::EncryptMessage(void){
	for (int i = 0; i < alfabet_message_.size(); ++i)
	{
		int j = i % alfabet_key_.size();
		alfabet_message_[i] += alfabet_key_[j];
		if (alfabet_message_[i] >= 26)
		{
			alfabet_message_[i] %= 26;
		}

		int value_of_letter = alfabet_message_[i];
		char letra_output = alfabet_[value_of_letter];
		encrypted_message_output_.push_back(letra_output);
	}
};
