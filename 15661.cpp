#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
/*
* 링크와 스타트
* (비트마스크를 이용한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	int S[20][20];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	int ans = INT_MAX;

	for (int l = 1; l < (1 << N) - 1; l++) {
		int start = 0;

		for (int i = 0; i < N - 1; i++)
			if ((l & (1 << i)) != 0)
				for (int j = i + 1; j < N; j++)
					if ((l & (1 << j)) != 0)
						start += S[i][j] + S[j][i];

		int link = 0;

		for (int i = 0; i < N - 1; i++)
			if ((l & (1 << i)) == 0)
				for (int j = i + 1; j < N; j++)
					if ((l & (1 << j)) == 0)
						link += (S[i][j] + S[j][i]);

		int diff = abs(start - link);
		ans = diff < ans ? diff : ans;
	}
	
	cout << ans;
	
	return 0;
}