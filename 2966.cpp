#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int a[3];
/*
* Âï±â
*/
int main() {
	char ans[100 + 1];
	char adrian[] = { 'A', 'B', 'C' };
	char bruno[] = { 'B', 'A', 'B', 'C' };
	char goran[] = { 'C', 'C', 'A', 'A', 'B', 'B' };
	int n;

	scanf("%d %s", &n, ans);
	for (int i = 0; i < n; i++) {
		if (ans[i] == adrian[i % 3]) a[0]++;
		if (ans[i] == bruno[i % 4]) a[1]++;
		if (ans[i] == goran[i % 6]) a[2]++;
	}

	int maximum = 0;
	for (int i = 0; i < 3; i++)
		if (a[i] > maximum) maximum = a[i];
	
	printf("%d\n", maximum);
	for (int i = 0; i < 3; i++)
		if (a[i] == maximum)
			printf("%s\n", (i == 0 ? "Adrian" : (i == 1 ? "Bruno" : "Goran")));

	return 0;
}