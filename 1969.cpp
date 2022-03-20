#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string dna[1000], s;
int alpha[26], n, m, ans;

void makeS() {
	int mm = 0;
	for (int i = 1; i < 26; i++)
		if (alpha[i] > alpha[mm]) mm = i;
	s.push_back('A' + mm);
	ans += (n - alpha[mm]);
	for (int i = 0; i < 26; i++) alpha[i] = 0;
}
/*
* DNA
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> dna[i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) alpha[dna[j][i] - 'A']++;
		makeS();
	}
	cout << s << endl
		<< ans << endl;

	return 0;
}