#include <iostream>
using namespace std;

int paper[128][128];
int ans[2];

bool oneColored(int sRow, int sCol, int N) {
	int first = paper[sRow][sCol];
	for (int i = sRow; i < sRow + N; i++)
		for (int j = sCol; j < sCol + N; j++)
			if (first != paper[i][j])
				return false;

	ans[first]++;
	return true;
}

void divide(int sRow, int sCol, int N) {
	if (!oneColored(sRow, sCol, N)) {
		divide(sRow, sCol, N / 2);
		divide(sRow, sCol + N / 2, N / 2);
		divide(sRow + N / 2, sCol, N / 2);
		divide(sRow + N / 2, sCol + N / 2, N / 2);
	}
}
/*
* 색종이 만들기
*/
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> paper[i][j];

	divide(0, 0, N);
	cout << ans[0] << "\n" << ans[1];

	return 0;
}