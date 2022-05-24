#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 50
#define CLOCK_WISE 8
using namespace std;

void dfs(int x, int y);
bool map[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int h, w;
/*
* ¼¶ÀÇ °³¼ö
*/
int main() {
	while (1) {
		int numberOfIslands = 0;

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;

		for (int row = 0; row < h; row++)
			for (int col = 0; col < w; col++)
				scanf("%d", &map[row][col]);

		for (int row = 0; row < h; row++)
			for (int col = 0; col < w; col++)
				if (!visited[row][col] && map[row][col]) {
					numberOfIslands++;
					dfs(row, col);
				}
		printf("%d\n", numberOfIslands);

		for (int row = 0; row < h; row++)
			for (int col = 0; col < w; col++)
				visited[row][col] = false;
	}

	return 0;
}

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < CLOCK_WISE; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < h && 0 <= ny && ny < w &&
			!visited[nx][ny] && map[nx][ny])
			dfs(nx, ny);
	}
}