#include <iostream>
using namespace std;

int dp[1000001];
/*
* 1�� �����
* (Memoization�� Ȱ���� �������� Bottom-Up����� Dynamic Programming ����.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = dp[i] ? min(dp[i / 2] + 1, dp[i]) : dp[i / 2] + 1;
		if (i % 3 == 0)
			dp[i] = dp[i] ? min(dp[i / 3] + 1, dp[i]) : dp[i / 3] + 1;
	}
	cout << dp[N];

	return 0;
}
/*
* N�� �Ҽ��� ���� �ݵ�� dp[N - 1] + 1�� �����ǰ�
* N�� 2�� ����̰� 3�� ����� �ƴ� ������ dp[N - 1]�� dp[N / 2] �� �� �ּҰ� + 1�� �����ǰ�
* N�� 2�� ����� �ƴϰ� 3�� ����� ������ dp[N - 1]�� dp[N / 3] �� �� �ּҰ� + 1�� �����ǰ�
* N�� 6�� ����� ������ dp[N - 1]�� dp[N / 2]�� dp[N / 3] �� �� �ּҰ� + 1�� �����ȴ�.
* dp[1] = 0
* dp[2] = 1
* dp[3] = 1
* dp[4] = 2
* dp[5] = 3
* dp[6] = 2
* dp[7] = 3
* dp[8] = 3
* dp[9] = 2
* dp[10] = 3
* ...
*/