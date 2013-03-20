#include "Rijndael.hpp"

/*
-------------------------------------------------------
----------------------- PRIVATE -----------------------
-------------------------------------------------------
*/

void Rijndael::LoadFromFiles(string FileName, vector<int>& ToVector){
	ifstream file;
	int InputFromFileToVector;
	file.open(FileName.c_str());
	while(!file.eof())
	{
		file >> hex >> InputFromFileToVector;
		ToVector.push_back(InputFromFileToVector);
	}
	file.close();
} 

vector<int> Rijndael::SubBytes (vector<int> Message, vector<int> SBox){
	vector<int> ByteSubResult;
	for (int i = 0; i < Message.size(); i++)
		ByteSubResult.push_back(SBox[Message[i]]);
	return ByteSubResult;
};

vector<int> Rijndael::ShiftRows (vector<int> Message){
	vector<int> ShiftRowsResult = Message;

	swap (ShiftRowsResult[1], ShiftRowsResult[5]);
	swap (ShiftRowsResult[5], ShiftRowsResult[9]);
	swap (ShiftRowsResult[9], ShiftRowsResult[13]);

	swap (ShiftRowsResult[2], ShiftRowsResult[10]);
	swap (ShiftRowsResult[6], ShiftRowsResult[14]);

	swap (ShiftRowsResult[15], ShiftRowsResult[11]);
	swap (ShiftRowsResult[11], ShiftRowsResult[7]);
	swap (ShiftRowsResult[7], ShiftRowsResult[3]);

	return ShiftRowsResult;
};

vector<int> Rijndael::AddRoundKey (vector<int> Message, vector<int> Key){
	vector<int> XORResult;
	for (int i = 0; i < Message.size(); i++)
		XORResult.push_back(Message[i] ^ Key[i]);
	return XORResult;
};

vector<int> Rijndael::SubKey (vector<int> Key, vector<int>& Rcon, vector<int> SBox){
	vector<int> SubKey;
	vector<int> PartialSubKey;

	PartialSubKey = PartialSubKeyRW(Key);

	PartialSubKey = SubBytes(PartialSubKey, sbox_);

	PartialSubKey = PartialSubKeyXORKeyInitial(PartialSubKey, SubKey, Key, Rcon);

	for (int i = 4; i < 16; i += 4)
	{
		PartialSubKey = PartialSubKeyXORKey(PartialSubKey, SubKey, Key, i, i+4);
	}
	
	Rcon.erase (Rcon.begin(), Rcon.begin()+4);
	return SubKey;
};

vector<int> Rijndael::PartialSubKeyRW(vector<int> Key){
	vector<int> initialpartialsubkey;
	
	for (int i = 12; i < 16; ++i)
	{
		initialpartialsubkey.push_back(Key[i]);
	}
		
	swap (initialpartialsubkey[0], initialpartialsubkey[1]);
	swap (initialpartialsubkey[1], initialpartialsubkey[2]);
	swap (initialpartialsubkey[2], initialpartialsubkey[3]);

	return initialpartialsubkey;
};

vector<int> Rijndael::PartialSubKeyXORKeyInitial(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, vector<int> Rcon){
	vector<int> initialpartialsubkey = PartialSubKey;
	for (int i = 0; i < 4; ++i)
	{
		initialpartialsubkey[i] ^= Key[i] ^ Rcon[i];
		SubKey.push_back(initialpartialsubkey[i]);
	}
	return initialpartialsubkey;
};

vector<int> Rijndael::PartialSubKeyXORKey(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, int begin, int end){
	for (int i = begin; i < end; ++i)
	{
		PartialSubKey[i % 4] ^= Key[i];
		SubKey.push_back(PartialSubKey[i % 4]);
	}
	return PartialSubKey;
};

vector<int> Rijndael::MixColumns(vector<int> Message, vector<int> Matrix){
	vector <int> Solution(16,0);
	
	int pos_actual = 0;
	
	for (int k = 0; k < 16; k+=4)
	{
		for(int i=0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				if(Matrix[i*4+j] == 1){
					Solution[pos_actual] ^= Message[j + k];
				}
					
				else if (Matrix[i*4+j] == 2){
					Solution[pos_actual] ^= X2(Message[j + k]);
				}
				else if(Matrix[i*4+j] == 3){
					Solution[pos_actual] ^= X3(Message[j + k] );
				}
					
			}
			pos_actual++;
		}
	}

	return Solution;
};

int Rijndael::X2 (int Number){
	bitset<8> n_xor = 0x1b;
	bitset<8> aux = Number;

	if (aux[7] == 1)
	{
		aux <<=1;
		aux = aux ^ n_xor;
	}else{
		aux <<=1;
	}

    int Result = (int)aux.to_ulong();
	return Result;
};

int Rijndael::X3 (int Number){
	int a = X2(Number);
	a ^= Number;
	return a;
};

void Rijndael::VerVector(vector<int> input){
	for (int i = 0; i < input.size(); ++i)
	{
		cout << hex << input[i] << " ";
	}
	cout << endl;
};

/*
-------------------------------------------------------
----------------------- PUBLIC ------------------------
-------------------------------------------------------
*/

Rijndael::Rijndael(){
	LoadFromFiles("message.txt", message_);
	LoadFromFiles("key.txt", key_);
	LoadFromFiles("sbox.txt", sbox_);
	LoadFromFiles("matrix.txt", matrix_);
	LoadFromFiles("rcon.txt", rcon_);
};

Rijndael::~Rijndael(){};

void Rijndael::Encrypt(void){
	vector<int> encrypted_message = message_;
	vector<int> subkeys = key_;
	
	cout << "Clave: "; VerVector(subkeys);
	cout << "Bloque de Texto Original: "; VerVector(encrypted_message);
	encrypted_message = AddRoundKey(encrypted_message, subkeys);
	cout << endl;
	
	cout << "R" << 0 << ":" << endl;
	cout << "Subclave: "; VerVector(subkeys);
	cout << "Mensaje: "; VerVector(encrypted_message);
	
	for (int i = 0; i < 9; ++i){
		encrypted_message = SubBytes(encrypted_message, sbox_);
		
		encrypted_message = ShiftRows(encrypted_message);
		
		encrypted_message = MixColumns(encrypted_message, matrix_);
		
		subkeys = SubKey(subkeys, rcon_, sbox_);
		encrypted_message = AddRoundKey(encrypted_message, subkeys);
		
		cout << "R" << dec << i+1 << ":" << endl;
		cout << "Subclave: "; VerVector(subkeys);
		cout << "Mensaje: "; VerVector(encrypted_message);
	}


	encrypted_message = SubBytes(encrypted_message, sbox_);
	encrypted_message = ShiftRows(encrypted_message);
	subkeys = SubKey(subkeys, rcon_, sbox_);
	encrypted_message = AddRoundKey(encrypted_message, subkeys);
		
	cout << "R" << dec << 10 << ":" << endl;
	cout << "Subclave: "; VerVector(subkeys);
	cout << "Mensaje: "; VerVector(encrypted_message);
	
	cout << endl;

	cout << "Bloque de Texto Cifrado: ";
	VerVector(encrypted_message);
}