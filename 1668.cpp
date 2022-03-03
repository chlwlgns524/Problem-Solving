#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* 트로피 진열
*/
int main() {
	int* trophy;
	int n;
	
	scanf("%d", &n);
	trophy = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &trophy[i]);

	int fromTheLeft = 1;
	int highest = trophy[0];
	for (int i = 1; i < n; i++)
		if (trophy[i] > highest) {
			highest = trophy[i];
			fromTheLeft++;
		}

	int fromTheRight = 1;
	highest = trophy[n - 1];
	for (int i = n - 2; i >= 0; i--)
		if (trophy[i] > highest) {
			highest = trophy[i];
			fromTheRight++;
		}
	printf("%d\n%d\n", fromTheLeft, fromTheRight);

	delete[] trophy;
	return 0;
}