#include <iostream>
using namespace std;

int dp[1000001];
/*
* 1로 만들기
* (Memoization을 활용한 전형적인 Bottom-Up방식의 Dynamic Programming 문제.)
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
* N이 소수일 경우는 반드시 dp[N - 1] + 1로 결정되고
* N이 2의 배수이고 3의 배수가 아닐 때에는 dp[N - 1]과 dp[N / 2] 둘 중 최소값 + 1로 결정되고
* N이 2의 배수가 아니고 3의 배수일 때에는 dp[N - 1]과 dp[N / 3] 둘 중 최소값 + 1로 결정되고
* N이 6의 배수일 때에는 dp[N - 1]과 dp[N / 2]와 dp[N / 3] 셋 중 최소값 + 1로 결정된다.
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