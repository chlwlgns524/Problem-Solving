#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

bool isPal(const string s);
/*
* ÆÓ¸°µå·Ò¼ö
*/
int main() {
	while (1) {
		string str;
		cin >> str;
		if (str[0] == '0') break;

		if (isPal(str)) 
			cout << "yes\n";
		else 
			cout << "no\n";
	}

	return 0;
}

bool isPal(const string s) {
	int i = 0;
	int j = s.length() - 1;

	while (i < j)
		if (s[i++] != s[j--]) 
			return false;

	return true;
}