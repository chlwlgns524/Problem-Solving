#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
/*
* �Ǻ���ġ ��
* (�ܼ� ����Լ� ȣ���� �̿��� ���� �ذ��� �ð� �ʰ��� �߻��Ѵ�.)
*/
int main() {
	int n;

	scanf("%d", &n);

	vector<int> f(n + 1);
	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 2] + f[i - 1];
	
	printf("%d\n", f[n]);

	return 0;
}
/* 
* �ð� �ʰ�
int fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
*/