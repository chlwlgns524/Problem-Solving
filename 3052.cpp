#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define DIVISOR 42

using namespace std;
/*
* ³ª¸ÓÁö
*/
int main() {
	vector<int> remainders(DIVISOR);
	int numberOfInput = 10;
	int n;

	while (numberOfInput) {
		scanf("%d", &n);
		remainders[n % DIVISOR]++;
		numberOfInput--;
	}
	
	int diffrentFromEachOther = 0;

	for (int i = 0; i < DIVISOR; i++)
		if (remainders[i] > 0)
			diffrentFromEachOther++;

	printf("%d\n", diffrentFromEachOther);

	return 0;
}