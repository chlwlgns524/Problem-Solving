#include <iostream>
using namespace std;
typedef unsigned long long int ull;

ull dp[91][2];
/*
* 이친수
* (결론적으로 이 문제의 상황은 피보나치 수열을 의미한다. 구체적으로 어떻게 피보나치
* 수열로 정의될 수 있는지는 아래 주석을 참고할 것.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][0] + dp[n][1];

	return 0;
}

/*
* n자리 이친수는 다음과 같이 구할 수 있다.
* dp[n] = dp[n][0] + dp[n][1]
* (이때, [n][0]은 n자리 이친수의 마지막 자리에 0이 올 경우의 수이고
* [n][1]은 n자리 이친수의 마지막 자리에 1이 올 경우의 수로 정의한다.)
* 
* dp[n][0] = dp[n - 1][0] + dp[n - 1][1] = dp[n - 1]
* dp[n][1] = dp[n - 1][0]
* 
* dp[n]	= dp[n][0] + dp[n][1];
*		= dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][0]
*		= dp[n - 1] + dp[n - 1][0]
*		= dp[n - 1] + dp[n - 2][0] + dp[n - 2][1]
*		= dp[n - 1] + dp[n - 2] => 피보나치 수열
* 
* N = 1
* 1
* 
* N = 2
* 10
* 
* N = 3
* 100
* 101
* 
* N = 4
* 1000
* 1001
* 1010
* 
* N = 5
* 10000
* 10001
* 10010
* 10100
* 10101
* 
* N = 6
* 100000
* 100001
* 100010
* 100100
* 100101
* 101000
* 101001
* 101010
* 
* ...
*/