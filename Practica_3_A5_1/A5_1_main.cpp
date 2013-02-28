#include "A5_1.hpp"

void GetKey(vector<int>& key);
void GetMessage(vector<int>& message);

int main(){
	system("clear");
	A5_1 a;
	cout << "major  "<<a.FuncionMayoritaria() << endl;
	cout << "encryot ";
	//a.BitEncrypt();
	cout << endl;
	a.Encrypt();
	a.VerOutput();
	//a.CalcularEntrada(Key1_, LFSR1_);
};

void GetKey(vector<int>& key){
	int indice = 1, integer;
	cout << "Introduce los valores de la clave (-1 para acabar)" << endl;
	cout << "Elemento " << indice << ": ";
	cin >> integer;
	while (integer != -1){
		key.push_back(integer);
		indice++;
		cout << "Elemento " << indice << ": ";
		cin >> integer;
	}
};

void GetMessage(vector<int>& message){
	int indice = 1, integer;
	cout << "Introduce los valores del mensaje (-1 para acabar)" << endl;
	cout << "Elemento " << indice << ": ";
	cin >> integer;
	while (integer != -1){
		message.push_back(integer);
		indice++;
		cout << "Elemento " << indice << ": ";
		cin >> integer;
	}
};