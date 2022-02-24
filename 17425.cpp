#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
const int MAX_NUM = 1000000;

ull f[MAX_NUM + 1], g[MAX_NUM + 1];

void pre_process() {
	for (int i = 1; i <= MAX_NUM; i++)
		for (int j = 1; i * j <= MAX_NUM; j++)
			f[i * j] += i;

	// Dynamic Programming
	for (int x = 1; x <= MAX_NUM; x++)
		g[x] = g[x - 1] + f[x];
}
/*
* 약수의 합
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pre_process();

	int T, N;	
	cin >> T;
	while (T--) {
		cin >> N;
		cout << g[N] << "\n";
	}
	
	return 0;
}