#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

bool isFriends(string s1, string s2) {
	int l1 = 0, l2 = 0, len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < len1; i++)
		l1 |= (1 << (s1[i] - '0'));
	for (int i = 0; i < len2; i++)
		l2 |= (1 << (s2[i] - '0'));
	return l1 == l2;
}

bool almostFriends(string s1, string s2) {
	string s[2] = { s1, s2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0, len = s[i].size(); j < len - 1; j++) {
			string str = s[i];
			str[j] = s[i][j] - 1;
			str[j + 1] = s[i][j + 1] + 1;
			if (str[0] != '0' && isFriends(str, s[!i])) return true;

			str[j] = s[i][j] + 1;
			str[j + 1] = s[i][j + 1] - 1;
			if (str[0] != '0' && isFriends(str, s[!i])) return true;
		}
	}
	return false;
}
/*
* µðÁöÅÐ Ä£±¸
*/
int main() {
	int t = 3;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (isFriends(s1, s2)) cout << "friends\n";
		else if (almostFriends(s1, s2)) cout << "almost friends\n";
		else cout << "nothing\n";
	}

	return 0;
}