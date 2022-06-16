#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int unit[6] = { 500, 100, 50, 10, 5, 1 };
/*
* °Å½º¸§µ·
*/
int main() {
	int payment, change;
	int n = 0;

	scanf("%d", &payment);
	change = 1000 - payment;

	for (int i = 0; i < 6; i++)
		if (change / unit[i]) {
			n += change / unit[i];
			change %= unit[i];
		}
	printf("%d\n", n);

	return 0;
}