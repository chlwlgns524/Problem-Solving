#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* 수학적 호기심
*/
int main() {
	int t;
	
	scanf("%d", &t);
	while (t--) {
		int n, m, ans = 0;
		scanf("%d %d", &n, &m);

		for (int a = 1; a < n - 1; a++)
			for (int b = a + 1; b < n; b++)
				if ((a * a + b * b + m) % (a * b) == 0)
					ans++;

		printf("%d\n", ans);
	}

	return 0;
}