#include <iostream>
using namespace std;

int stair[301], dp[301][3];
/*
* 계단 오르기
* (문제에서 제시된 제한사항을 이차원 배열로 구현한 후 Dynamic Programming을
* 이용한 풀이. 특히 어떤 계단으로 1 step 도약할 때와 2 step 도약할 때를 
* 나누어서 생각한다.)
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