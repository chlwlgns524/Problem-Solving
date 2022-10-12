#include <iostream>
using namespace std;

int D[101][101];
int min(int a, int b) { return a < b ? a : b; }
/*
* 플로이드
* (Floyd-Warshall algorithm을 이용한 풀이. Time complexity는 O(n^3).)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (D[from][to])
			D[from][to] = min(D[from][to], cost);
		else
			D[from][to] = cost;
	}

	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				if (D[from][via] == 0 || D[via][to] == 0 || from == to)
					continue;
				if (D[from][to] == 0 || D[from][via] + D[via][to] < D[from][to])
					D[from][to] = D[from][via] + D[via][to];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}