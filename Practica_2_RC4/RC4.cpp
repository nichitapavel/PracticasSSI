#include "RC4.hpp"

/*
---------------------- PRIVATE METHODS ----------------------
*/

void RC4::View(void){
	for (int i = 0; i < 128; i=i+3)
	{
		cout << S[i] << "   S " << S[i+1] << "    S " << S[i+2] << "    S " << endl;
	}
}

void RC4::Initialization(void){
	int j = 0;
	for (int i = 0; i < 256; ++i)
	{
		j = (j + S[i] + K[i]) % 256;
		swap(S[i], S[j]);
	}
	View();
}

/*
void RC4::PRGA(void){

}


/*
---------------------- PUBLIC METHODS ----------------------
*/

/*
METHOD Constructor
se le pasa dos parametros: clave y mensaje
la clave y el mensaje se guarda en los atributos del objeto
y se populiza el vector del alfabeto
*/

RC4::RC4(vector<int> key, vector<int> message){
	key_ = key;
	message_ = message;
	int key_size = key_.size();
	for (int i = 0; i < 256; ++i)
	{
		S.push_back(i);
		K.push_back(key_[i % key_size]);
	}
	Initialization();
};

/*
METHOD Destructor
*/

RC4::~RC4(){};

void RC4::ViewPosition(int j){
	cout << S[j] << endl;
}

void RC4::PRGA(){
	int k = 0, j = 0, t;
	for (int i = 0; i < message_.size(); ++i)
	{
		k = (k + 1) % 256;
		j = (j + S[k]) % 256;
		swap(S[k], S[j]);
		t = (S[k] + S[j]) % 256;
		C.push_back(S[t] + message_[i]);
	}
}

void RC4::ViewC(void){
	for (int i = 0; i < C.size(); ++i)
	{
		string a;
		stringstream s;
		s << C[i];
		a = s.str();
		cout << s <<  endl;
	}
}