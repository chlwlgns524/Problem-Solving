#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* 달팽이는 올라가고 싶다
*/
int main() {
	int A, B, V, day;

	scanf("%d %d %d", &A, &B, &V);

	if ((V - A) % (A - B) == 0)
		day = (V - A) / (A - B);
	else
		day = (V - A) / (A - B) + 1;

	day++;
	printf("%d\n", day);

	return 0;
}