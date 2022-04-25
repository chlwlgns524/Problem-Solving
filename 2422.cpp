#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool avoid[201][201];
int n, m, ans;
/*
* 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
*/
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int first, second;
		scanf("%d %d", &first, &second);
		if (first > second) swap(first, second);
		avoid[first][second] = true;
	}

	for (int i = 1; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++) 
			for (int k = j + 1; k <= n; k++) 
				if (!avoid[i][j] && !avoid[i][k] && !avoid[j][k]) ans++;
	printf("%d\n", ans);

	return 0;
}