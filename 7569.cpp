#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tomato {
	int h;
	int r;
	int c;
	int day;
};

vector<vector<vector<int>>> storage;
int row, col, height, last;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void spread();
/*
* Åä¸¶Åä
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> col >> row >> height;
	storage.resize(height);
	for (int i = 0; i < height; i++) {
		storage[i].resize(row);
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				int state;
				cin >> state;
				storage[i][j].push_back(state);
			}
		}
	}
	
	spread();
	
	for (int i = 0; i < height; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				if (!storage[i][j][k]) {
					cout << "-1";
					return 0;
				}
	cout << last;
	
	return 0;
}

void spread() {
	queue<Tomato> q;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < row; j++)
			for (int k = 0; k < col; k++)
				if (storage[i][j][k] == 1)
					q.push({ i, j, k, 0 });
	
	while (!q.empty()) {
		int h = q.front().h;
		int r = q.front().r;
		int c = q.front().c;
		int day = q.front().day;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (0 <= nr && nr < row && 0 <= nc && nc < col
				&& !storage[h][nr][nc]) {
				storage[h][nr][nc] = 1;
				q.push({ h, nr, nc, day + 1 });
				last = day + 1;
			}
		}

		for (auto dh : { 1, -1 }) {
			int nh = h + dh;

			if (0 <= nh && nh < height && !storage[nh][r][c]) {
				storage[nh][r][c] = 1;
				q.push({ nh, r, c, day + 1 });
				last = day + 1;
			}
		}
	}
}