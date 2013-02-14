#include <string>
#include <iostream>
#include <vector>
#include "stdlib.h"

#define MOD 26;

using namespace std;

class Vigenere
{
	string key_;
	string message_;
	string encrypted_message_output_;
	vector<int> alfabet_message_;
	vector<int> alfabet_key_;
	vector<char> alfabet_;

private:
	void Alfabet(void);
	int IntegerOfLetter(char letra);
	void StringToInteger(string message, vector<int>& output);
	void EncryptMessage(void);

public:
	Vigenere(string key, string message);
	~Vigenere(void);
	void Encrypt(void);
	void UnEncrypt(void);
};