#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string res = "zzzzzzzzzzz";
string word;
int length;
void reorganize(int s1, int s2);
inline void reverse(string& str);
/*
* 단어 나누기
*/
int main() {
	cin >> word;
	length = word.size();

	for (int i = 1; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
			reorganize(i, j);
	cout << res;

	return 0;
}

void reorganize(int s1, int s2) {
	string str1, str2, str3;
	for (int i = 0; i < s1; i++)
		str1.push_back(word[i]);
	for (int i = s1; i < s2; i++)
		str2.push_back(word[i]);
	for (int i = s2; i < length; i++)
		str3.push_back(word[i]);
	reverse(str1);
	reverse(str2);
	reverse(str3);
	res = (str1 + str2 + str3) < res ? (str1 + str2 + str3) : res;
}

inline void reverse(string& str) {
	string temp = str;
	for (int i = 0, len = str.size(); i < len; i++) str[i] = temp[len - 1 - i];
}