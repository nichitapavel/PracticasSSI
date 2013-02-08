#include "Vigenere.hpp"

int main(){
	string key, message;
	/*
	cout << "Dame Clave: ";
	cin >> key;
	cout << "Dame Mensaje: ";
	cin >> message;
	*/
	key = "MISION";
	message = "ESTEMENSAJESEAUTODESTRUIRA";
	
	Vigenere a(key, message);
	a.encrypt();
	a.showencription();
	a.unencrypt();
	a.showunencription();
}