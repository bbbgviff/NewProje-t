#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

bool isLogged() {
	string username, password, un, pw;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read("D:\\Data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
		return true;
	else
		return false;

}

bool checkPassword(string pw) {
	bool isCorrectLength = false;
	bool isSpecialSymb = false;
	bool isTwoNumbers = false;
	bool capitalLetters = false;

	set<char> specialSymbols{ '!', '@', '#', '$', '%', '^', '&', '*' };
	if (pw.size() > 7)
		isCorrectLength = true;
	else {
		cout << "Password is too short" << endl;
		isCorrectLength = false;
	}

	for (int i = 0; i < pw.size(); i++) {
		if (specialSymbols.count(pw[i])) {
			isSpecialSymb = true;
		}
	}
	if (!isSpecialSymb)
		cout << "Password doesn't have any special symbols!" << endl;
	int numbersCount = 0;
	for (int i = 0; i < pw.size(); i++) {
		if ((int)pw[i] >= 48 && (int)pw[i] <= 57)
			numbersCount++;
	}
	//проверка на наличие заглавных букв латинницы
	for (char ch : pw) {
		if (ch >= 65 && ch <= 90)
			capitalLetters = true;
	}

	if (numbersCount >= 2)
		isTwoNumbers = true;
	else
		cout << "Password might have two or more digits!" << endl;
	if (isCorrectLength && isSpecialSymb && isTwoNumbers && capitalLetters)
		return true;
	else
		return false;

}

int main() {
	int choice;

	cout << "1: Register\n2: Login\nWhat do you want: ";
	cin >> choice;

	if (choice == 1) {
		string username, password;
		cout << "Enter username: ";
		cin >> username;
		while (1) {
			cout << "Enter password: ";
			cin >> password;
			if (checkPassword(password))
				break;
		}

		ofstream file;
		file.open("D:\\Data\\" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2) {
		bool status;
		status = isLogged();

		if (status) {
			cout << "Successfully logged in!" << endl;
			main();
		}
		else {
			cout << "Incorrect login or password!" << endl;
			main();
		}
	}

}
