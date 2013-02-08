#include <string>
#include <iostream>
#include <vector>
//#include <stdlib.h>
#define MOD 26;

using namespace std;

class Vigenere
{
	string key_;
	string message_;
	string encrypted_message_output_;
	string unencrypted_message_output_;
	vector<int> encrypted_message_;
	vector<int> encrypted_key_;
	vector<char> alfabet_;

private:
	void stringtoascii(void);
	void alfabet(void);
	int EnteroDeLetra(char letra);

public:
	Vigenere(string key, string message);
	~Vigenere(void);
	void encrypt(void);
	void showencription(void);
	void unencrypt(void);
};