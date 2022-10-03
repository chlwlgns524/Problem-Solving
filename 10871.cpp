#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* X보다 작은 수
*/
int main() {

	int a, x;

	scanf("%d %d", &a, &x);

	for (int i = 0; i < a; i++) {
		int ans;

		scanf("%d", &ans);

		if (ans < x)
			printf("%d ", ans);
	}
	puts("");

	return 0;
}