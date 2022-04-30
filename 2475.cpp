#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* °ËÁõ¼ö
*/
int main() {
	int n;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &n);
		sum += (n * n);
	}
	printf("%d\n", sum % 10);

	return 0;
}