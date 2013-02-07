#include "Vigenere.hpp"

int main(){
	string key, message;
	cout << "Dame Clave: ";
	cin >> key;
	cout << "Dame Mensaje: ";
	cin >> message;
	
	Vigenere a(key, message);
	a.encrypt();
}