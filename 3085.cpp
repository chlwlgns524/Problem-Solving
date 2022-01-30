#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];
int n, ans;

void checkToRight(int i, int j);
void checkToDown(int i, int j);
void hCheck();
void vCheck();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != board[i][j + 1])
				checkToRight(i, j);
			if (board[i][j] != board[i + 1][j])
				checkToDown(i, j);
		}
	}

	cout << ans;

	return 0;
}

void checkToRight(int i, int j) {
	swap(board[i][j], board[i][j + 1]);

	hCheck();
	vCheck();

	swap(board[i][j], board[i][j + 1]);
}

void checkToDown(int i, int j) {
	swap(board[i][j], board[i + 1][j]);

	hCheck();
	vCheck();

	swap(board[i][j], board[i + 1][j]);
}

void hCheck() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;

		for (int j = 0; j < n; j++) {
			if (board[i][j] == board[i][j + 1])
				cnt++;
			else {
				ans = ans > cnt ? ans : cnt;
				cnt = 1;
			}
		}
	}
}

void vCheck() {
	for (int i = 0; i < n; i++) {
		int cnt = 1;

		for (int j = 0; j < n; j++) {
			if (board[j][i] == board[j + 1][i])
				cnt++;
			else {
				ans = ans > cnt ? ans : cnt;
				cnt = 1;
			}
		}
	}
}