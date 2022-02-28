#include <iostream>
#include <cmath>
#define MAX_DIGIT 8
using namespace std;

int numbers[MAX_DIGIT + 1];

void make_digits() {
	for (int digit = 1; digit <= MAX_DIGIT; digit++) {
		int numberOfBetween = pow(10, digit) - pow(10, digit - 1);
		numbers[digit] = numberOfBetween * digit;
	}
}
/*
* 수 이어 쓰기 1
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	make_digits();

	int N, ans = 0;
	
	cin >> N;

	for (int digit = 1; digit <= MAX_DIGIT; digit++) {
		int begin = pow(10, digit - 1);
		int end = pow(10, digit);

		if (begin <= N && N < end) {
			int numberOfBetween = (N - (begin - 1));
			ans += numberOfBetween * digit;
			break;
		}
		else
			ans += numbers[digit];
	}

	if (N == 100000000) ans += 9;

	cout << ans;
	
	return 0;
}

/*	  range	  digit
* -------------------
* [10^0, 10^1)  1
* [10^1, 10^2)  2
* [10^2, 10^3)  3
* [10^3, 10^4)  4
* [10^4, 10^5)  5
* [10^5, 10^6)  6
* [10^6, 10^7)  7
* [10^7, 10^8)  8
* [10^8]
*/
