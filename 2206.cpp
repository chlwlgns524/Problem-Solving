#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int bfs(int startX, int startY);
int map[MAX + 1][MAX + 1];
int dist[MAX + 1][MAX + 1][2];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m;

struct position {
	int x;
	int y;
	bool canBreak;
};
/*
* 벽 부수고 이동하기
* (아래와 같은 입력이 들어올 때 출력을 살펴볼 것.)
* 
* 4 4
* 0101
* 0101
* 0001
* 1110
*/
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	printf("%d\n", bfs(1, 1));

	return 0;
}

int bfs(int startX, int startY) {
	queue<position> q;

	q.push({ startX, startY, true });
	dist[startX][startY][true] = 1;
	dist[startX][startY][false] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		bool canBreak = q.front().canBreak;
		
		if (x == n && y == m)
			return dist[x][y][canBreak];
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !dist[nx][ny][canBreak]) {
				if (!map[nx][ny]) {
					q.push({ nx, ny, canBreak });
					dist[nx][ny][canBreak] = dist[x][y][canBreak] + 1;
				}
				else if (map[nx][ny] && canBreak) {
					q.push({ nx, ny, !canBreak });
					dist[nx][ny][!canBreak] = dist[x][y][canBreak] + 1;
				}
			}
		}

		q.pop();
	}

	return -1;
}