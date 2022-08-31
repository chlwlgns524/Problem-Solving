#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

void spread();
int storage[MAX + 1][MAX + 1];
int dx[] = { -1, 0, 1, 0 };
int dy[] = {  0, 1, 0, -1};
int row, col;
int last;
struct tomato {
	int x;
	int y;
	int day;
};
/*
* ≈‰∏∂≈‰
*/
int main() {
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			scanf("%d", &storage[i][j]);
		
	spread();

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (!storage[i][j]) {
				printf("-1\n");
				
				return 0;
			}
	printf("%d\n", last);
	
	return 0;
}

void spread() {
	queue<tomato> q;

	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (storage[i][j] == 1) q.push({ i, j, 0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int day = q.front().day;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (1 <= nx && nx <= row && 1 <= ny && ny <= col && !storage[nx][ny]) {
				storage[nx][ny] = 1;
				q.push({ nx, ny, day + 1 });
				if (day + 1 > last) last = day + 1;
			}
		}

		q.pop();
	}
}