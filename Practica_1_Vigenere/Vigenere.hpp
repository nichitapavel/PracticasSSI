#include <string>
#include <iostream>
#include <vector>
//#include <stdlib.h>
#define MODULE 26;

using namespace std;

class Vigenere
{
	string key_;
	string message_;
	string encrypted_message_;

private:
	void stringtoascii(void);

public:
	Vigenere(string key, string message);
	~Vigenere();
	void encrypt();
};