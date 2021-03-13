#include <iostream>
#include <string>

using namespace std;

class Gronfeld {

private:

	//Алфавит с пробелом
	string alphabet = "abcdefghijklmnopqrstuvwxyz ";

public:

	//Методы
	string Encrypt(string, string key);
	string Decrypt(string, string key);
	string GenerateKey(string key, int lenght);
	int FindLetter(char letter);
};
int main() {

	Gronfeld Cipher;

	string mode;
	string text;
	string key;

	cout << "\t\t~~ Try the Count Gronfeld Cipher ~~" << endl << endl;
	cout << "\t\t~~ Do you want to encrypt or decrypt text? ~~" << endl;
	do {
		cout << "\t\t~~ Please select a mode ~~" << endl;

		cin >> mode;

		//Шифрование
		if (mode == "encrypt") {

			cout << "\t\t~~ Please enter a string for encryption ~~" << endl;
			cin.get();
			getline(cin, text);
			cout << "\t\t~~ Please enter a key for encryption ~~" << endl;
			cin >> key;

			cout << "Result: '" << Cipher.Encrypt(text, key) << "'" << endl;
		}
		//Дешифрование
		else if (mode == "decrypt") {

			cout << "\t\t~~ Please enter a string for decryption ~~" << endl;
			cin >> text;
			cout << "\t\t~~ Please enter a key for decryption ~~" << endl;
			cin >> key;

			cout << "Result: '" << Cipher.Decrypt(text, key) << "'" << endl;
		}
		else {

			cout << "\t\tInvalid mode, please try again.." << endl;
			return 0;
		}

	} while (true);
}

//Шифратор
string Gronfeld::Encrypt(string text, string key)
{
	string rezultKey = GenerateKey(key, text.size());
	string rezult = "";
	for (int i = 0; i < text.size(); i++) {
		
		if (FindLetter(text[i]) + ((int)rezultKey[i]) - 48 >= alphabet.size()) {
			rezult.push_back(alphabet[(FindLetter(text[i]) + ((int)rezultKey[i]) - 48) - alphabet.size()]);
		}
		else {
			rezult.push_back(alphabet[FindLetter(text[i]) + ((int)rezultKey[i]) - 48]);
		}
	}
	
	return rezult;
}

//Дешифратор
string Gronfeld::Decrypt(string text, string key)
{
	string rezultKey = GenerateKey(key, text.size());
	string rezult = "";
	for (int i = 0; i < text.size(); i++) {

		if (FindLetter(text[i]) - ((int)rezultKey[i] - 48) < 0) {
			rezult.push_back(alphabet[alphabet.size() - ((((int)rezultKey[i]) - 48) - FindLetter(text[i]))]);
		}
		else {
			rezult.push_back(alphabet[FindLetter(text[i]) - ((int)rezultKey[i] - 48)]);
		}
	}
	return rezult;
}

//Перезаписываем ключ в цикле
string Gronfeld::GenerateKey(string key, int lenght)
{
	string newKey;
	int count = 0;

	for (int i = 0; i < lenght; i++) {

		newKey.push_back(key[count]);
		count++;
		if (count == key.size()) { count = 0; }
	}

	return newKey;
}

int Gronfeld::FindLetter(char letter) {

	for (int i = 0; i < 26; i++) {
		if (letter == alphabet[i]) { return i; }
	}
}
