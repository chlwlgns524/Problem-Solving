#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* º° Âï±â - 3
*/
int main() {
	int n;
	
	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}