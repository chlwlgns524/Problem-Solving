#include <iostream>
#include <algorithm>
#include <string>
#define MAX 15
using namespace std;

char alpha[MAX];
int L, C;
int vowel, consonant;

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void findPassword(int prev, int depth, string pwd) {
	if (depth == L) {
		if (vowel >= 1 && consonant >= 2)
			cout << pwd << "\n";
		return;
	}

	for (int i = prev + 1; i < C; i++) {
		if (isVowel(alpha[i])) {
			vowel++;
			findPassword(i, depth + 1, pwd + alpha[i]);
			vowel--;
		}
		else {
			consonant++;
			findPassword(i, depth + 1, pwd + alpha[i]);
			consonant--;
		}
	}
}
/*
* 암호 만들기
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++)
		cin >> alpha[i];

	sort(alpha, alpha + C);

	findPassword(-1, 0, "");

	return 0;
}