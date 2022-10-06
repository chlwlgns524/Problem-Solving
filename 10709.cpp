#include <iostream>
using namespace std;

char ch;
int ans[101][101], H, W;
/*
* 기상캐스터
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> ch;
			if (ch == 'c')
				ans[i][j] = 0;
			else
				ans[i][j] = -1;
		}

	for (int i = 0; i < H; i++) {
		cout << ans[i][0] << " ";
		for (int j = 1; j < W; j++) {
			if ((ans[i][j] != 0) && (ans[i][j - 1] >= 0))
				ans[i][j] = ans[i][j - 1] + 1;
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}