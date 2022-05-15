#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* º° Âï±â - 8
*/
int main() {
	int n;
	
	scanf("%d", &n);
	for (int i = 1; i <= n * 2; i++) {
		if (i <= n) {
			for (int j = 0; j < n * 2; j++)
				if (j < i || j >= n * 2 - i)
					printf("*");
				else
					printf(" ");
			printf("\n");
		}
		else {
			for (int j = 0; j < n * 2; j++)
				if (j < n * 2 - i || j >= i)
					printf("*");
				else
					printf(" ");
			printf("\n");
		}
	}
		
	return 0;
}