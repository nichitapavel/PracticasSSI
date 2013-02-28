#include "RC4.hpp"

void GetKey(vector<int>& key);
void GetMessage(vector<int>& message);

int main(){
	system("clear");
	vector<int> key, message;
	
	key.push_back(2);
	key.push_back(5);
	message.push_back(1);
	message.push_back(34);
	//GetKey(key);
	system("clear");
	//GetMessage(message);
	system("clear");

	cout << "******************* RESULT *******************" << endl;
	cout << endl;
	RC4 a(key, message);
	a.Encrypt();
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