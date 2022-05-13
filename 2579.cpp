#include <iostream>
using namespace std;

int stair[301], dp[301][3];
/*
* ��� ������
* (�������� ���õ� ���ѻ����� ������ �迭�� ������ �� Dynamic Programming��
* �̿��� Ǯ��. Ư�� � ������� 1 step ������ ���� 2 step ������ ���� 
* ����� �����Ѵ�.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1][1] = stair[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = stair[i] + max(dp[i - 2][1], dp[i - 2][2]);
		dp[i][2] = stair[i] + dp[i - 1][1];
	}
	cout << (dp[n][1] > dp[n][2] ? dp[n][1] : dp[n][2]);

	return 0;
}