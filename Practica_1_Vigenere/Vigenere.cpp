#include "Vigenere.hpp"

/*
---------------------- PRIVATE METHODS ----------------------
*/

/*
METHOD Alfabet populiza el vector alfabet_ con letras
*/

void Vigenere::Alfabet(void){
	for (int i = 0; i < MOD; ++i)
	{
		//('A' + i) utilizando ascii, empezando con el caracter 'A'
		// le vamos sumando i, de esta manera se pasa al siguiente caracter
		// B, C, D...
		// con push_back se mete al final del vector alfabet_
		alfabet_.push_back('A' + i);
	}
};

/*
METHOD IntegerOfLetter retorna el indice de la letra
que se recibe como parametro
*/

int Vigenere::IntegerOfLetter(char letter){
	for (int i = 0; i < MOD; ++i)
	{
		if (alfabet_[i] == letter)
		{
			return i;
		}
	}
};

/*
METHOD StringToInteger pasa la cadena recibida a un vector de enteros
output va por referencia porque a este metodo se le puede llamar varias
veces con diferentes outputs
*/

void Vigenere::StringToInteger(string input, vector<int>& output){
	// variable que guarda el indice devuelto por IntegerOfLetter()
	int integer_of_letter;
	for (int i = 0; i < input.size(); ++i)
	{	
		// Para cada caracter llamas s IntegerOfLetter() con el caracter
		integer_of_letter = IntegerOfLetter(input[i]);
		// el resultado lo insertas por detras en output
		output.push_back(integer_of_letter); 
	}
};

/*
METHOD EncryptMessage finaliza la encryptacion
*/

void Vigenere::EncryptMessage(void){
	int j, value_of_letter;
	char letter_output;
	for (int i = 0; i < alfabet_message_.size(); ++i)
	{
		// Para cada caracter de alfabet_message_
		// calculamos la posicion "j" del entero que se sumara
		// La operacion modulo me asegura que siempre tendre una "j"
		// en el rango de la clave
		j = i % alfabet_key_.size();
		// Se le suma a alfabet_message_ el entero del cual tenemos la
		// posicion
		alfabet_message_[i] += alfabet_key_[j];
		// si el resultado final es mayor a tamaño del alfabeto
		// calculamos el modulo, asi nos aseguramos que siempre
		// cogeremos un caracter del alfabeto
		if (alfabet_message_[i] >= MOD)
		{
			alfabet_message_[i] %= MOD;
		}

		// Tenemos el mensaje encryptado con enteros
		// ahora lo encryptados con carateres
		// en value_of_letter guardamos la posicion del caracter
		value_of_letter = alfabet_message_[i];
		// en letter_output guardamos el caracter asociado
		letter_output = alfabet_[value_of_letter];
		// se inserta por detras el caracter en encrypted_message_output_
		encrypted_message_output_.push_back(letter_output);
	}
};

/*
---------------------- PUBLIC METHODS ----------------------
*/

/*
METHOD Constructor
se le pasa dos parametros: clave y mensaje
la clave y el mensaje se guarda en los atributos del objeto
y se populiza el vector del alfabeto
*/

Vigenere::Vigenere(string key, string message){
	key_ = key;
	message_ = message;
	Alfabet();
};

/*
METHOD Destructor
*/

Vigenere::~Vigenere(){};

/*
METHOD Encrypt se le llama para encryptar la cadena
Se pasan a entero la clave y mensaje
despues se encrypta el mensaje y se saca por pantalla
*/

void Vigenere::Encrypt(){	
	StringToInteger(key_, alfabet_key_);
	StringToInteger(message_, alfabet_message_);
	
	EncryptMessage();

	cout << "Encrypted Message: " << encrypted_message_output_ << endl;
	cout << endl;
};

/*
METHOD UnEncrypt desencripta el mensaje a su forma casi original
y lo suelta en la consola
*/

void Vigenere::UnEncrypt(void){
	// Se guarda el emsanje desencriptado
	string unencrypted_message_output_;
	int j, value_of_letter;
	char letter;
	for (int i = 0; i < alfabet_message_.size(); ++i)
	{
		// Para cada caracter de alfabet_message_
		// calculamos la posicion "j" del entero que se restara
		// La operacion modulo me asegura que siempre tendre una "j"
		// en el rango de la clave
		j = i % alfabet_key_.size();
		// La resta para establecer el entero original
		value_of_letter = alfabet_message_[i] - alfabet_key_[j];
		// si el resultado de la resta es menor a 0
		// le sumamos el modulo, asi obtenemos una posicion valida
		// que ademas es la letra original
		if (value_of_letter < 0)
		{
			value_of_letter += MOD;
		}
		
		// obtenemos el caracter de la posicion calculada antes
		letter = alfabet_[value_of_letter];
		// y la insertamos por detras en el string que guarda
		// el mensaje desincriptado
		unencrypted_message_output_.push_back(letter);
	}

	cout << "Uncrypted Message: " << unencrypted_message_output_ << endl;
	cout << endl;
};