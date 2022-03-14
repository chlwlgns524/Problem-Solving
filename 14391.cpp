#include <iostream>
#include <string>
#define MAX 4
using namespace std;

int paper[MAX][MAX];
/*
* 종이 조각
* (비트 마스크를 활용한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;	
		for (int j = 0; j < M; j++)
			paper[i][j] = s[j] - '0';
	}

	int ans = 0;

	for (int l = 0; l < (1 << (N * M)); l++) {
		int sum = 0;

		for (int i = 0; i < N; i++) {
			int cur = 0;

			for (int j = 0; j < M; j++) {
				int k = i * M + j;

				if ((l & (1 << k)) == 0)
					cur = cur * 10 + paper[i][j];
				else {
					sum += cur;
					cur = 0;
				}	
			}

			sum += cur;
		}

		for (int j = 0; j < M; j++) {
			int cur = 0;

			for (int i = 0; i < N; i++) {
				int k = i * M + j;

				if ((l & (1 << k)) != 0)
					cur = cur * 10 + paper[i][j];
				else {
					sum += cur;
					cur = 0;
				}
			}

			sum += cur;
		}

		ans = sum > ans ? sum : ans;
	}
	cout << ans;

	return 0;
}