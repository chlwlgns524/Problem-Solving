#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define N 100
#define CARDINAL_POINTS 4
using namespace std;

void dfs(int x, int y, int limit);
int spot[N + 1][N + 1];
int visited[N + 1][N + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int minimum = 101;
int maximum = 0;
int secureArea;
int n;
/*
* 안전 영역
*/
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int value;
			scanf("%d", &value);
			spot[i][j] = value;
			if (value > maximum) maximum = value;
			if (value < minimum) minimum = value;
		}

	for (int height = minimum - 1; height <= maximum; height++) {
		int examinedArea = 0;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!visited[i][j] && spot[i][j] > height) {
					dfs(i, j, height);
					examinedArea++;
				}

		if (examinedArea > secureArea) secureArea = examinedArea;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
	}
	printf("%d\n", secureArea);

	return 0;
}

void dfs(int x, int y, int limit) {
	visited[x][y] = true;

	for (int i = 0; i < CARDINAL_POINTS; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < n &&
			!visited[nx][ny] && spot[nx][ny] > limit)
			dfs(nx, ny, limit);
	}
}