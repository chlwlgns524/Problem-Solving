#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	
	return true;
}
/*
* 골드바흐의 추측
* (6 ≤ n ≤ 1000000인 범위에서 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우는
* 존재하지 않으므로 이 경우를 고려하지 않더라도 상관없다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;
		
		for (int a = 3, limit = n / 2; a <= limit; a += 2)
			if (isPrime(a) && isPrime(n - a)) {
				cout << n << " = " << a << " + " << n - a << "\n";			
				break;
			}	
	}		

	return 0;
}