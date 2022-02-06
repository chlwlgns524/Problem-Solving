#include <iostream>
#include <vector>
using namespace std;

vector<int> cost(21), res(21), dp(2001, 999999999);
/*
* 호텔
* (입력값으로 받을 목표 고객량 C의 값은 최대 1000이다. 
* 그러나 최적의 값을 구하기 위해 1000을 훌쩍 넘는 고객량이 나올수도 있다. 
* 따라서 배열 dp의 크기를 넉넉하게 2000으로 할당받는다. 왜냐하면 홍보 비용을 들여서 
* 늘릴 수 있는 고객량의 크기는 최대 100으로 주어지기 때문이다.)
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