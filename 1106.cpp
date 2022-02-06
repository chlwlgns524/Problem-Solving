#include <iostream>
#include <vector>
using namespace std;

vector<int> cost(21), res(21), dp(2001, 999999999);
/*
* ȣ��
* (�Է°����� ���� ��ǥ ���� C�� ���� �ִ� 1000�̴�. 
* �׷��� ������ ���� ���ϱ� ���� 1000�� ��½ �Ѵ� ������ ���ü��� �ִ�. 
* ���� �迭 dp�� ũ�⸦ �˳��ϰ� 2000���� �Ҵ�޴´�. �ֳ��ϸ� ȫ�� ����� �鿩�� 
* �ø� �� �ִ� ������ ũ��� �ִ� 100���� �־����� �����̴�.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int target, n;
	cin >> target >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i] >> res[i];
	
	dp[0] = 0;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= n; j++)
			if (i - res[j] >= 0) 
				dp[i] = min(dp[i], dp[i - res[j]] + cost[j]);

	int mn = dp[target];
	for (int i = target; i <= 2000; i++)
		if (dp[i] < mn) mn = dp[i];
	cout << mn;
	
	return 0;
}