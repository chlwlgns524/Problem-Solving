#include <iostream>
using namespace std;

int seq[100000];
/*
* 수열
* (문제의 상황을 그대로 구현한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, ans = 1, len1 = 1, len2 = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	for (int i = 1; i < n; i++) {
		if (seq[i] >= seq[i - 1]) len1++;
		else len1 = 1;
		ans = len1 > ans ? len1 : ans;
	}
	for (int i = 1; i < n; i++) {
		if (seq[i] <= seq[i - 1]) len2++;
		else len2 = 1;
		ans = len2 > ans ? len2 : ans;
	}
	cout << ans;

	return 0;
}