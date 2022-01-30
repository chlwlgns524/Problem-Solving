#include <iostream>
using namespace std;

bool broken[10];
int n, m, ans;

int moveToChannel(int ch);
/*
* 리모컨
* (브루트 포스를 활용한 풀이. 시간 복잡도는 O(N).
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}

	ans = abs(n - 100);
	for (int i = 0; i < 1000000; i++) {
		int numOfBtn = moveToChannel(i);
		
		if (numOfBtn > 0) {
			int numOfPlusMinus = abs(n - i);
			int total = numOfBtn + numOfPlusMinus;

			ans = total < ans ? total : ans;
		}
	}
	cout << ans;

	return 0;
}

int moveToChannel(int ch) {
	if (ch == 0) {
		if (broken[0] == true)
			return 0;
		else
			return 1;
	}

	int numOfBtn = 0;
	while (ch > 0) {
		if (broken[ch % 10] == true)
			return 0;

		numOfBtn++;
		ch /= 10;
	}

	return numOfBtn;
}