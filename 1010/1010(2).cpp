#include <iostream>
using namespace std;
/*
* 다리 놓기
* (단순한 Combination 문제. 그러나 단순히 팩토리얼 연산을 수행하면
* 에러가 발생한다. 따라서 팩토리얼 연산을 에러 없이 수행하는 것이 관건.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int M, N, pick = 1, ans = 1;
		cin >> N >> M;
		while (pick <= N) {
			ans *= M;
			ans /= pick;
			M--;
			pick++;
		}
		cout << ans << "\n";
	}

	return 0;
}