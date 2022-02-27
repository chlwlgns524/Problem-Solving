#include <iostream>
#define MAX_NUM 1000000
using namespace std;

bool isNotPrime[MAX_NUM + 1];

void check_prime() {
	for (int i = 2; i * i <= MAX_NUM; i++)
		if (!isNotPrime[i])
			for (int j = i + i; j <= MAX_NUM; j += i)
				isNotPrime[j] = true;
}
/*
* 골드바흐의 추측
* (에라토스테네스의 체를 이용한 효율적인 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	check_prime();

	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		for (int a = 3, limit = n / 2; a <= limit; a += 2)
			if (!isNotPrime[a] && !isNotPrime[n - a]) {
				cout << n << " = " << a << " + " << n - a << "\n";
				break;
			}				
	}
	
	return 0;
}