#include <iostream>
using namespace std;

int dp[30][30];
/*
* �ٸ� ����
* (Dynamic Programming�� Ȱ���� Ǯ��. Dynamic Programming���� 
* ���װ���� ��Ÿ���� �Ľ�Į�� �ﰢ���� ������.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 29; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		dp[i][i] = 1;
	}

	int T, M, N;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << dp[M][N] << "\n";
	}

	return 0;
}