#include "Vigenere.hpp"

string GetString(void);

int main(){
	system("clear");
	string key, message;
	cout << "Key: ";
	cin >> key;

	message = GetString();

	cout << endl;
	cout << "******************* RESULT *******************" << endl;
	cout << endl;
	Vigenere a(key, message);
	a.Encrypt();
	a.UnEncrypt();
	cin.get();
	system("clear");
};

string GetString(void){
 	char space = ' ';
 	int i;
 	string message;
 	
 	cout << "Message: ";
 	cin.get();
 	getline(cin, message);
 	
 	i = message.find(space);
 	while (i != -1){
 		message.erase(i, 1);
 		i = message.find(space);
 	}

 	return message;
};