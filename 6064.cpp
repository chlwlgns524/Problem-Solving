#include <iostream>
using namespace std;
/*
* 카잉 달력
* (y가 N과 같을 경우를 고려해서 x와 y를 1씩 빼준 후 연산한다.)
*/
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		x--;
		y--;
		bool found = false;
		for (int k = x; k < M * N; k += M) {
			if (k % N == y) {
				found = true;
				cout << k + 1<< "\n";
				break;
			}
		}
		if (!found) cout << "-1\n";
	}

	return 0;
}