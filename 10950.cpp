#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* A+B - 3
*/
int main() {
	int t, a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}