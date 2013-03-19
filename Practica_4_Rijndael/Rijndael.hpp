#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "stdlib.h"

using namespace std;

class Rijndael
{
	vector<int> sbox_;
	vector<int> message_;
	vector<int> key_;
	vector<int> matrix_;
	vector<int> rcon_;
	vector<int> state_intermedia_;

private:
	void VerVector(vector<int> input);
	void LoadFromFiles(string FileName, vector<int>& ToVector);
	vector<int> AddRoundKey (vector<int> Message, vector<int> Key);
	vector<int> SubBytes (vector<int> Message, vector<int> SBox);
	vector<int> ShiftRows (vector<int> Message);
	vector<int> SubKey(vector<int> Key, vector<int>& Rcon, vector<int> SBox);
	vector<int> PartialSubKeyXORKey(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, int begin, int end);
	vector<int> PartialSubKeyInitialization(vector<int> Key);
	vector<int> PartialSubKeyInitial(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, vector<int> Rcon);

public:
	Rijndael();
	~Rijndael();
	void nada(void);
};