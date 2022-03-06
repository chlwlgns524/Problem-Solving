#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(100001, 99999999);
/*
* 제곱수의 합
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 316; i++)
		dp[i * i] = 1;
	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j * j < i; j++)
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
	cout << dp[n];

	return 0;
}