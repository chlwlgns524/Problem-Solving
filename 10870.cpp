#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int fibonacci(int n);
/*
* �Ǻ���ġ �� 5
* (Memoization�� ���� ���� Ƚ���� ������ �ʰ� �ܼ� ��� ȣ�⸸���� Ǯ�̰� ������ ����.)
*/
int main() {
	int n;

	scanf("%d", &n);
	printf("%d\n", fibonacci(n));

	return 0;
}

int fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibonacci(n - 2) + fibonacci(n - 1);
}