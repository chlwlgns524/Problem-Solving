#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* º° Âï±â - 2
*/
int main() {
	int n;

	scanf("%d", &n);
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++)
			putchar(' ');
		for (int k = 0; k < n - i; k++)
			putchar('*');
		puts("");
	}

	return 0;
}