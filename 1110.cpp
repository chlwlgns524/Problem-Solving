#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* 더하기 사이클
*/
int main() {
	int numberOfCycles = 0;
	int n, original;

	scanf("%d", &n);

	if (n < 10) n *= 10;
	
	original = n;

	do {
		int a = n / 10;
		int b = n % 10;

		n = b * 10 + ((a + b) % 10);

		numberOfCycles++;
	} while (n != original);

	printf("%d\n", numberOfCycles);

	return 0;
}