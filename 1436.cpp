#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

inline bool check(int n) {
	string s = to_string(n);
	int len = s.size();
	for (int i = 0; i <= len - 3; i++)
		if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6') return true;
	return false;
}
/*
* ¿µÈ­°¨µ¶ ¼ò
*/
int main() {
	int n, i = 666, cnt = 0;
	scanf("%d", &n);
	for (; cnt != n; i++)
		if (check(i)) cnt++;
	printf("%d\n", i - 1);

	return 0;
}