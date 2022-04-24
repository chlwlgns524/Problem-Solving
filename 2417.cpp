#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int ull;
/*
* 정수 제곱근
* (Overflow에 주의할 것.)
*/
int main() {
	ull n, ans = 0;

	cin >> n;
	ull start = 1, end = n;
	while (start <= end) {
		ull middle = (start + end) / 2;

		if (middle >= sqrt(n)) {
			end = middle - 1;
			ans = middle;
		}
		else 
			start = middle + 1;
	}
	cout << ans;

	return 0;
}