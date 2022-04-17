#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* 숫자 게임
*/
int main() {
	short player[1000], card[1000][5], ans = 0, n;
	scanf("%hd", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			scanf("%hd", &card[i][j]);

	for (int i = 0; i < n; i++) {
		short mm = 0;
		for (int a = 0; a < 3; a++)
			for (int b = a + 1; b < 4; b++)
				for (int c = b + 1; c < 5; c++)
					if ((card[i][a] + card[i][b] + card[i][c]) % 10 > mm)
						mm = (card[i][a] + card[i][b] + card[i][c]) % 10;
		player[i] = mm;
		ans = player[i] > ans ? player[i] : ans;
	}

	for (int i = n - 1; i >= 0; i--)
		if (player[i] == ans) {
			printf("%hd\n", i + 1);
			break;
		}
		
	return 0;
}