#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* Doubles
*/
int main() {
	while (1) {
		int num[15], len = 0, ans = 0, n;
		scanf("%d", &n);
		while (n != -1 && n != 0) {
			num[len++] = n;
			scanf("%d", &n);
		}
		if (n == -1) return 0;

		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				if (i != j && num[j] == num[i] * 2) ans++;
		printf("%d\n", ans);
	}
}