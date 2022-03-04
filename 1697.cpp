#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 100001
#define THREE_CASES 3
using namespace std;

void bfs(int root);
int seconds[MAX];
int movement[] = { -1, 1, 0 };
int teleport[] = { 1, 1, 2 };
int n, k;
/*
* ¼û¹Ù²ÀÁú
*/
int main() {
	scanf("%d %d", &n, &k);
	
	if (n >= k)
		printf("%d\n", n - k);
	else {
		bfs(n);
		printf("%d\n", seconds[k]);
	}

	return 0;
}

void bfs(int root) {
	queue<int> q;

	q.push(root);
	while (!q.empty()) {
		int currentPosition = q.front();

		for (int i = 0; i < THREE_CASES; i++) {
			int nextPosition = currentPosition * teleport[i] + movement[i];
			

			if (0 <= nextPosition && nextPosition < MAX && nextPosition != root
				&& !seconds[nextPosition]) {
				q.push(nextPosition);
				seconds[nextPosition] = seconds[currentPosition] + 1;
			}

			if (nextPosition == k) return;
		}

		q.pop();
	}
}