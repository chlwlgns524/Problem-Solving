#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define LIMIT 10001

using namespace std;

void d(int n);

vector<int> v(LIMIT);
/*
* ¼¿ÇÁ ³Ñ¹ö
*/
int main() {
	for (int i = 1; i < LIMIT; i++)
		d(i);
	
	for (int i = 1; i < LIMIT; i++)
		if (!v[i])
			printf("%d\n", i);
		
	return 0;
}

void d(int n) {
	int temp = n;
	while (temp) {
		n += (temp % 10);
		temp /= 10;
	}

	if (n >= LIMIT || v[n] > 0)
		return;
	else {
		v[n]++;

		d(n);
	}
}