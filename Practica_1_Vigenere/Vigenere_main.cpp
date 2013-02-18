#include "Vigenere.hpp"

string GetMessage(void);

int main(){
	system("clear");
	string key, message;
	cout << "Key: ";
	cin >> key;

	transform(key.begin(), key.end(), key.begin(), ::toupper);

	message = GetMessage();

	cout << endl;
	cout << "******************* RESULT *******************" << endl;
	cout << endl;
	Vigenere a(key, message);
	a.Encrypt();
	a.UnEncrypt();
	cin.get();
	system("clear");
};

/*
METHOD GetMessage obtiene el mensaje que se quiere encriptar
sin la necesitat del usuario de escribir el mensaje sin espacios
*/

string GetMessage(void){
 	// declaraciones iniciales, el espacio blanco que se utilizara para cazar
 	// i guardamos la posicion del espacio en blanco
 	// message se guarda el mensaje sin espacios
 	char space = ' ';
 	int i;
 	string message;
 	
 	// el usuario introduce el mensaje y lo guardamos en message con espacios
 	cout << "Message: ";
 	cin.get();
 	getline(cin, message);
 	
 	// se obtiene la posicion del primer espacio blanco encontrado
 	i = message.find(space);
 	// si no se encuentra espacion en blanco se devuelve -1
 	// hasat que encuentra espacio blanco en
 	while (i != -1){
 		//borras el espacio de la posicion i y
 		// como es solo un caracter, tamaño 1
 		message.erase(i, 1);
 		// se vuelve a buscar el siguiente espacio
 		i = message.find(space);
 	}

 	// pasar a UPPERCASE si es necesario
 	transform(message.begin(), message.end(), message.begin(), ::toupper);
 	
 	// se devuelve el mensaje sin espacios
 	return message;
};