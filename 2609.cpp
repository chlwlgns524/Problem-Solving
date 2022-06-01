#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int gcd(int dividend, int divisor);
/*
* 최대공약수와 최소공배수
*/
int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	int d = gcd(a, b);
	int m = a * b / d;

	printf("%d\n%d\n", d, m);
	
	return 0;
}

int gcd(int dividend, int divisor) {
	while (divisor) {
		int temp = dividend % divisor;
		dividend = divisor;
		divisor = temp;
	}

	return dividend;
}