#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
/*
* �Ǻ���ġ �� 2
* (��°��� ������ ����Ѵ�.)
*/
int main() {
	int n;

	scanf("%d", &n);

	vector<unsigned long long> f(n + 1);
	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 2] + f[i - 1];
	
	printf("%llu\n", f[n]);

	return 0;
}