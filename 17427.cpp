#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
const int MAX_NUM = 1000000;

ull f[MAX_NUM + 1], g[MAX_NUM + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; i * j <= N; j++)
			f[i * j] += i;

	for (int x = 1; x <= N; x++)
		g[x] = g[x - 1] + f[x];

	cout << g[N];

	return 0;
}