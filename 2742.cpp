#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/*
* ���� N
*/
using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	for (int i = n; i > 0; i--)
		printf("%d\n", i);

	return 0;
}