#include <iostream>
using namespace std;

int buttons[] = { 300, 60, 10 }, ans[3];
/*
* 전자레인지
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < 3; i++) {
		ans[i] = T / buttons[i];
		T %= buttons[i];
	}

	if (T)
		cout << -1;
	else
		for (auto e : ans) cout << e << " ";
		
	return 0;
}