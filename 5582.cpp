#include <iostream>
#include <string>
using namespace std;

int LCS[4001][4001];
/*
* 공통 부분 문자열
* (대표적인 최장 공통 부분문자열(Longest Common Substring) 알고리즘 문제.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	string str1, str2;
	cin >> str1 >> str2;

	str1.insert(0, "0");
	str2.insert(0, "0");
	for (int i = 1, len2 = str2.size(); i < len2; i++)
		for (int j = 1, len1 = str1.size(); j < len1; j++)
			if (str1[j] == str2[i]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
				ans = LCS[i][j] > ans ? LCS[i][j] : ans;
			}
	cout << ans;

	return 0;
}