#include <iostream>
using namespace std;
/*
* 팩토리얼 0의 개수
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num = i;
		while (num) {
			if (num % 5 == 0) {
				ans++;
				num /= 5;
			}
			else break;
		}
	}
	cout << ans;

	return 0;
}