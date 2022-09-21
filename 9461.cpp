#include <iostream>
using namespace std;

unsigned long long int dp[101];
/*
* 파도반 수열
* (제시된 그림과 상황을 잘 살펴보고 피보나치 수열을 응용하여 문제를 해결한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
}