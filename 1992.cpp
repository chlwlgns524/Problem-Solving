#include <iostream>
#include <string>
using namespace std;

char screen[64][64];

bool compressedToZero(int sRow, int sCol, int N) {
	for (int i = sRow; i < sRow + N; i++)
		for (int j = sCol; j < sCol + N; j++)
			if (screen[i][j] != '0')
				return false;
	return true;
}

bool compressedToOne(int sRow, int sCol, int N) {
	for (int i = sRow; i < sRow + N; i++)
		for (int j = sCol; j < sCol + N; j++)
			if (screen[i][j] != '1')
				return false;
	return true;
}

string quadTree(int sRow, int sCol, int N) {
	if (compressedToZero(sRow, sCol, N))
		return "0";
	else if (compressedToOne(sRow, sCol, N))
		return "1";
	else
		return "(" + quadTree(sRow, sCol, N / 2) +
		quadTree(sRow, sCol + N / 2, N / 2) +
		quadTree(sRow + N / 2, sCol, N / 2) +
		quadTree(sRow + N / 2, sCol + N / 2, N / 2) + ")";
}
/*
* ÄõµåÆ®¸®
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> screen[i][j];

	cout << quadTree(0, 0, N);

	return 0;
}