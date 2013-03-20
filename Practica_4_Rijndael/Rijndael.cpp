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

vector<int> Rijndael::AddRoundKey (vector<int> Message, vector<int> Key){
	vector<int> XORResult;
	for (int i = 0; i < Message.size(); i++)
		XORResult.push_back(Message[i] ^ Key[i]);
	return XORResult;
};

vector<int> Rijndael::SubBytes (vector<int> Message, vector<int> SBox){
	vector<int> ByteSubResult;
	for (int i = 0; i < Message.size(); i++)
		ByteSubResult.push_back(SBox[Message[i]]);
	return ByteSubResult;
};

vector<int> Rijndael::ShiftRows (vector<int> Message){
	vector<int> ShiftRowsResult = Message;

	// ROTACIONES FILA 2
	swap (ShiftRowsResult[1], ShiftRowsResult[5]);
	swap (ShiftRowsResult[5], ShiftRowsResult[9]);
	swap (ShiftRowsResult[9], ShiftRowsResult[13]);

	// ROTACIONES FILA 3
	swap (ShiftRowsResult[2], ShiftRowsResult[10]);
	swap (ShiftRowsResult[6], ShiftRowsResult[14]);

	// ROTACIONES FILA 4
	swap (ShiftRowsResult[15], ShiftRowsResult[11]);
	swap (ShiftRowsResult[11], ShiftRowsResult[7]);
	swap (ShiftRowsResult[7], ShiftRowsResult[3]);

	return ShiftRowsResult;
};

vector<int> Rijndael::PartialSubKeyXORKey(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, int begin, int end){
	for (int i = begin; i < end; ++i)
	{
		PartialSubKey[i % 4] ^= Key[i];
		SubKey.push_back(PartialSubKey[i % 4]);
	}
	return PartialSubKey;
}


vector<int> Rijndael::PartialSubKeyInitial(vector<int> PartialSubKey, vector<int>& SubKey, vector<int> Key, vector<int>& Rcon){
	vector<int> initialpartialsubkey = PartialSubKey;
	for (int i = 0; i < 4; ++i)
	{
		initialpartialsubkey[i] ^= Key[i] ^ Rcon[i];
		SubKey.push_back(initialpartialsubkey[i]);
	}

	Rcon.erase (Rcon.begin(), Rcon.begin()+4);
	//VerVector(Rcon);
	return initialpartialsubkey;
}

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
}

vector<int> Rijndael::SubKey (vector<int> Key, vector<int>& Rcon, vector<int> SBox){
	vector<int> SubKey; // Vector con la Clave antigua
	vector<int> PartialSubKey;  // Vector auxiliar para el cálculo de cada columna de la nueva clase

	PartialSubKey = PartialSubKeyRW(Key);

	PartialSubKey = SubBytes(PartialSubKey, sbox_);

	PartialSubKey = PartialSubKeyInitial(PartialSubKey, SubKey, Key, Rcon);
	//cout << "hola4" << endl;
	for (int i = 4; i < 16; i += 4)
	{
		PartialSubKey = PartialSubKeyXORKey(PartialSubKey, SubKey, Key, i, i+4);
	}
	
	Rcon.erase (Rcon.begin(), Rcon.begin()+4);
	return SubKey;
};

void Rijndael::VerVector(vector<int> input){
	for (int i = 0; i < input.size(); ++i)
	{
		cout << hex << input[i] << " ";
	}
	cout << endl;
}

vector<int> Rijndael::MixColumns(vector<int> Message, vector<int> Matrix){
	vector <int> solucion;
	solucion.resize(16,0);
	
	int pos_actual = 0;
	int cont = 0;
	int aux = 0;
	
	while(aux < 4)
	{
		for(int i=0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				//cout<<cont<<endl;
				if(Matrix[i*4+j] == 1){
					solucion[pos_actual] ^= X1(Message[j + cont]);
				}
					
				else if (Matrix[i*4+j] == 2){
					solucion[pos_actual] ^= X2(Message[j + cont]);
				}
				else if(Matrix[i*4+j] == 3){
					solucion[pos_actual] ^= X3(Message[j + cont] );
				}
					
			}
			pos_actual++;
		}
		cont += 4;
		aux ++;
	}

	return solucion;
}

int Rijndael::X1 (int Number){
	return Number;
}


int Rijndael::X2 (int Number){
	bitset<8> n_xor = 0x1b;//ojear si es este
	bitset<8> aux = Number;

	if (aux[7] == 1)
	{
		aux <<=1;
		aux = aux ^ n_xor;
	}else{
		aux <<=1;
	}

    int resultado = (int)aux.to_ulong();
    //cout << hex << resultado << endl;
	return resultado;
}

int Rijndael::X3 (int Number){
	int a = X2(Number);
	
	a ^= Number;
	//cout << hex << a << endl;
	
	return a;
}

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


int Rijndael::X2 (int numero){

	bitset<8> n_xor = 0x1b;//ojear si es este
	bitset<8> aux = numero;


	if (aux[7] == 1)
	{
		aux <<=1;
		aux = aux ^ n_xor;
	}else{
		aux <<=1;
	}

   	//cout <<  hex << aux.to_ulong() << " long" << endl;
    int resultado = (int)aux.to_ulong();

	return resultado;
}

int Rijndael::X3 (int numero){
	int a = X2(numero);
	a ^= numero;
	cout << a << endl;
	return a;
}

vector<int> Rijndael::MixColumns(vector<int> Matrix, vector<int> Message){
	

	vector <int> MixColumsnPartial;
	MixColumsnPartial.resize(16,0);
	
	int pos_actual = 0;
	int cont = 0;
	int aux = 0;;
	
	while(aux < 4)
	{
		for(int i=0; i<4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				//cout<<cont<<endl;
				if(Matrix[i*4+j] == 1)
					MixColumsnPartial[pos_actual] ^= Message[j + cont];
				else if (Matrix[i*4+j] == 2)
					MixColumsnPartial[pos_actual] ^= X2(Message[j + cont]);
				else if(Matrix[i*4+j] == 3)
					MixColumsnPartial[pos_actual] ^= X3(Message[j + cont] );
			}
			pos_actual++;
		}
		cont += 4;
		aux ++;
	}
		
	return MixColumsnPartial;
}

void Rijndael::nada(void){
	vector<int> v;
	VerVector(key_);
	//cout << "hola1" << endl; 
	VerVector(matrix_);
	//cout << "hola2" << endl;
	//MixColumns(matrix_, message_);
	VerVector(rcon_);
	//cout << "hola3" << endl;
	v = SubKey(key_, rcon_, sbox_);
	//cout << "hola4" << endl;
	VerVector(rcon_);
	//cout << "hola5" << endl;
	//SubKey(key_, rcon_, sbox_);
}