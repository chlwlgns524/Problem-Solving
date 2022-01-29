#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX_N = 40;
int numberOfZero[MAX_N + 1] = { 1, 0 };
int numberOfOne[MAX_N + 1] = { 0, 1 };
/*
* 피보나치 함수
* (Bottom-Up Approach)
*/
int main() {
	for (int i = 2; i <= MAX_N; i++) {
		numberOfZero[i] = numberOfZero[i - 1] + numberOfZero[i - 2];
		numberOfOne[i] = numberOfOne[i - 1] + numberOfOne[i - 2];
	}

    int t;

	scanf("%d", &t);
    while (t--) {
        int n;

        scanf("%d", &n);
        printf("%d %d\n", numberOfZero[n], numberOfOne[n]);
    }

	return 0;
}
/*
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
*/
/*
*											  fibonacci(4)
*							fibonacci(3)			+			fibonacci(2)
*				fibonacci(2)	+	fibonacci(1)		fibonacci(1)	+	fibonacci(0)
* fibonacci(1)	+	fibonacci(0)	return 1;			return 1;			return 0;
* return 1;			return 0;
*/
/*
*				0  1
* fibonacci(0) (1, 0)
* fibonacci(1) (0, 1)
* fibonacci(2) (1, 1)
* fibonacci(3) (1, 2)
* fibonacci(4) (2, 3)
* fibonacci(5) (3, 5)
*		......
*/