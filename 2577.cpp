#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
/*
* 숫자의 개수
*/
int main() {
	vector<int> v(10);
	int a, b, c;

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	unsigned int n = a * b * c;
	
	while (n) {
		v[n % 10]++;
		n /= 10;
	}
	
	for (int i = 0; i < 10; i++)
		printf("%d\n", v[i]);

	return 0;
}