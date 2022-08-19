#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int move(int currentX, int currentY);
vector<vector<bool>> chess;
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int l, moveToX, moveToY;
struct pos {
	int x;
	int y;
	int numberOfMove;
};
/*
* 나이트의 이동
*/
int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int currentX, currentY;
		
		scanf("%d %d %d %d %d", &l, &currentX, &currentY, &moveToX, &moveToY);
		chess.resize(l);
		for (int i = 0; i < l; i++)
			chess[i].resize(l);

		printf("%d\n", move(currentX, currentY));
		for (int i = 0; i < l; i++)
			chess[i].clear();
	}
	
	return 0;
}

int move(int currentX, int currentY) {
	queue<pos> q;

	q.push({ currentX, currentY, 0});
	chess[currentX][currentY] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int nextMove = q.front().numberOfMove;

		if (x == moveToX && y == moveToY) return nextMove;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < l && 0 <= ny && ny < l && !chess[nx][ny]) {
				chess[nx][ny] = true;
				q.push({ nx, ny, nextMove + 1 });
			}
		}

		q.pop();
	}

	return -1;
}