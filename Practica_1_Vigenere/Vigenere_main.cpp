#include "Vigenere.hpp"

int main(){
	string key, message;
	

	key = "MISION";
	message = "ESTEMENSAJESEAUTODESTRUIRA";
	
	system("clear");
	Vigenere a(key, message);
	a.Encrypt();
	a.UnEncrypt();
};