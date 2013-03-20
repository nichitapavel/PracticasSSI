#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include "stdlib.h"

using namespace std;

class Rijndael
{
	vector<int> sbox_;
	vector<int> message_;
	vector<int> key_;
	vector<int> matrix_;
	vector<int> rcon_;

private:
	void LoadFromFiles(string FileName, vector<int>& ToVector);
	vector<int> SubBytes (vector<int> Message, vector<int> SBox);
	vector<int> ShiftRows (vector<int> Message);
	vector<int> AddRoundKey (vector<int> Message, vector<int> Key);
	vector<int> SubKey(vector<int> Key, vector<int>& Rcon, vector<int> SBox);
	vector<int> PartialSubKeyRW(vector<int> Key);
	vector<int> PartialSubKeyXORKeyInitial(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, vector<int> Rcon);
	vector<int> PartialSubKeyXORKey(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, int begin, int end);
	vector<int> MixColumns(vector<int> Message, vector<int> Matrix);
	int X2(int Number);
	int X3(int Number);
	void VerVector(vector<int> input);

public:
	Rijndael();
	~Rijndael();
	void Encrypt(void);
};