#include <string>
#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

class A5_1
{
	vector<int> Key1_;
	vector<int> Key2_;
	vector<int> Key3_;
	vector<int> LFSR1_;
	vector<int> LFSR2_;
	vector<int> LFSR3_;
	vector<int> clocking_bits_;
	vector<int> Output_;


private:
	void Output(vector<int> input);
	vector<int> GetInputKey(void);
	vector<int> GetInputLFSR(void);
	vector<int> GetInputClockingBits(void);
	void ReSetLFSR(vector<int>& input);
	void DefaultInput(void);
	void GetNewInput(void);
	void BitEncrypt(void);
	int  MajorityRule(void);
	int  CalculateEntryBit(vector<int> Key, vector<int> LFSR);
	void MoveKeyVector(vector<int>& Key, int input);
	void MoveContainer(void);
	void Output(void);

public:
	A5_1(void);
	~A5_1(void);

	void Encrypt(void);
};