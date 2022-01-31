#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col);
vector<vector<int>> field;
vector<vector<bool>> visited;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m;
/*
* 유기농 배추
* (가로의 길이 M이 column이고 세로의 길이 N이 row이다.)
*/
int main() {
	int t, k;

	scanf("%d", &t);
	while (t--) {
		int section = 0;
		scanf("%d %d %d", &m, &n, &k);

		field.resize(n);
		visited.resize(n);
		for (int i = 0; i < n; i++) {
			field[i].resize(m);
			visited[i].resize(m);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				field[i][j] = 0;
				visited[i][j] = false;
			}
		for (int i = 0; i < k; i++) {
			int row, col;
			scanf("%d %d", &col, &row);
			field[row][col] = 1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (field[i][j] && !visited[i][j]) {
					dfs(i, j);
					section++;
				}
		
		printf("%d\n", section);
	}

	return 0;
}

void dfs(int row, int col) {
	visited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int x = row + dx[i];
		int y = col + dy[i];

		if (0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && field[x][y] == 1)
			dfs(x, y);
	}
}