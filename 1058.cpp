#include <iostream>
using namespace std;
/*
* 친구
* (Floyd-Washall 알고리즘을 이용한 풀이. 시간복잡도는 O(n^3).)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	const int INF = 2147483647;

	int dist[51][51];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			cin >> ch;
			if (ch == 'Y')
				dist[i][j] = 1;
			else
				dist[i][j] = INF;
		}
	}
	
	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				if (from == to || dist[from][via] == INF || dist[via][to] == INF)
					continue;
				if (dist[from][to] > dist[from][via] + dist[via][to])
					dist[from][to] = dist[from][via] + dist[via][to];
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		for (int j = 1; j <= n; j++)
			if (dist[i][j] < 3) num++;
		if (num > ans) ans = num;
	}
	cout << ans;

	return 0;
}