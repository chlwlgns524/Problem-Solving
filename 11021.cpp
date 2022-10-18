#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* A+B - 7
*/
int main() {
	int t, a, b;

	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}

	return 0;
}