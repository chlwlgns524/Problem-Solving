#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* º° Âï±â - 4
*/
int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int k = 0; k < n - i; k++)
			printf("*");
		printf("\n");
	}

	return 0;
}