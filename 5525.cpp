#include <iostream>
#include <string>
using namespace std;
/*
* IOIOI
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string S;

	cin >> N >> M >> S;

	int io = 0, ans = 0;
	for (int i = 1; i < M; i++) {
		if (S[i - 1] == 'I' && S[i] == 'O')
			io++;
		else if (S[i - 1] == 'O' && S[i] == 'I')
			ans += (io >= N ? 1 : 0);
		else
			io = 0;
	}
	cout << ans;

	return 0;
}