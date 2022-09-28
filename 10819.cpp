#include <iostream>
#include <cmath>
#include <climits>
#define LIMIT 8
using namespace std;

int A[LIMIT];
int picked[LIMIT];
bool isPicked[LIMIT];
int N;
int ans = INT_MIN;

void findMax(int* a) {
	int absSum = 0;

	for (int i = 0; i < N - 1; i++)
		absSum += abs(a[i] - a[i + 1]);

	ans = absSum > ans ? absSum : ans;
}

void go(int depth) {
	if (depth == N) {
		findMax(picked);
		return;
	}

	for (int i = 0; i < N; i++)
		if (!isPicked[i]) {
			isPicked[i] = true;
			picked[depth] = A[i];
			go(depth + 1);
			isPicked[i] = false;
		}
}
/*
* 차이를 최대로
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	go(0);

	cout << ans;

	return 0;
}