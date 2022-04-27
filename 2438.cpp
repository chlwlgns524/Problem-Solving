#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
/*
* º° Âï±â - 1
*/
int main() {
	int n;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			printf("%c", '*');
		puts("");
	}

	return 0;
}