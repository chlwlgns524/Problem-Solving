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
* �������� ����
* (6 �� n �� 1000000�� �������� �� Ȧ�� �Ҽ��� ������ n�� ��Ÿ�� �� ���� ����
* �������� �����Ƿ� �� ��츦 ������� �ʴ��� �������.)
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