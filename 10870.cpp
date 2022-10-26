#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int fibonacci(int n);
/*
* 피보나치 수 5
* (Memoization을 통해 연산 횟수를 줄이지 않고 단순 재귀 호출만으로 풀이가 가능한 문제.)
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