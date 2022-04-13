#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX_LEN 100
#define CARDINAL_POINTS 4
using namespace std;

void bfs(int startX, int startY);
int maze[MAX_LEN + 1][MAX_LEN + 1];
int dist[MAX_LEN + 1][MAX_LEN + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n;
int m;
struct pos {
	int x;
	int y;
};
/*
* ¹Ì·Î Å½»ö
*/
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &maze[i][j]);

	bfs(1, 1);

	return 0;
}

void bfs(int startX, int startY) {
	queue<pos> q;

	q.push({ startX, startY });
	dist[startX][startY] = 1;
	while (!q.empty()) {
		int currentX = q.front().x;
		int currentY = q.front().y;

		if (currentX == n && currentY == m) {
			printf("%d\n", dist[currentX][currentY]);
			return;
		}

		for (int i = 0; i < CARDINAL_POINTS; i++) {
			int nx = currentX + dx[i];
			int ny = currentY + dy[i];

			if (0 <= nx && nx <= n && 0 <= ny && ny <= m && 
				maze[nx][ny] && !dist[nx][ny]) {
				dist[nx][ny] = dist[currentX][currentY] + 1;
				q.push({ nx, ny });
			}
		}

		q.pop();
	}
}