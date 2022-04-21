#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 

inline char toLowerCase(char ch);
/*
* 도비의 영어 공부
*/
int main() { 
	char ch;
	string str;
	while (1) { 
		int cnt = 0; 
		cin >> ch; 
		if (ch == '#') return 0; 
		getline(cin, str);
		for (int i = 0; str[i]; i++)
			if (ch == toLowerCase(str[i])) cnt++;

		printf("%c %d\n", ch, cnt);
	} 
}

inline char toLowerCase(char ch) {
	char temp = ch;
	if ('A' <= ch && ch <= 'Z')
		temp = 'a' + ch - 'A';
	return temp;
}