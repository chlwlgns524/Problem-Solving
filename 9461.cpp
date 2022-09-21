#include <iostream>
using namespace std;

unsigned long long int dp[101];
/*
* �ĵ��� ����
* (���õ� �׸��� ��Ȳ�� �� ���캸�� �Ǻ���ġ ������ �����Ͽ� ������ �ذ��Ѵ�.)
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