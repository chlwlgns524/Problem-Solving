#include <iostream>
#include <string>
using namespace std;

string operator *(const string& str, int n) {
	string res = "";
	for (int i = 0; i < n; i++)
		res += str;
	return res;
}

string operator *(int n, const string& str) {
	string res = "";
	for (int i = 0; i < n; i++)
		res += str;
	return res;
}

void makeEmpty(string& str, int bIndex, int eIndex) {
	for (int i = bIndex; i < eIndex; i++) str[i] = ' ';
}

void Cantor(string& str, int bIndex, int length) {
	if (length >= 3) {
		int dx = length / 3;
		Cantor(str, bIndex, length / 3);
		makeEmpty(str, bIndex + dx, bIndex + 2 * dx);
		Cantor(str, bIndex + 2 * dx, length / 3);
	}
}
/*
* Ä­Åä¾î ÁýÇÕ
*/
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int N;
	while (cin >> N) {
		string line = "-";
		int length = 1;

		for (int i = 0; i < N; i++)
			length *= 3;
		line = (line * length);
		Cantor(line, 0, length);
		cout << line << "\n";
	}

	return 0;
}