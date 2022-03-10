#include <iostream>
using namespace std;

int paper[2187][2187], ans[3];

void solve(int rStart, int cStart, int N) {
	bool found = true;
	int first = paper[rStart][cStart];
	
	if (N == 1) {
		ans[first + 1]++;
		return;
	}

	for (int i = rStart; i < rStart + N; i++)
		for (int j = cStart; j < cStart + N; j++)
			if (first != paper[i][j]) {
				found = false;
				break;
			}

	if (found)
		ans[first + 1]++;
	else {
		int dN = N / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				solve(rStart + dN * i, cStart + dN * j, dN);
	}
}
/*
* 종이의 개수
* (Divide & Conquer를 활용한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	solve(0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";
	
	return 0;
}