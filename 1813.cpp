#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int truth[100001];
/*
* 마지막 한마디
*/
int main() {
	int n, ans = -1;
	scanf("%d", &n);

	int s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		truth[s]++;
	}

	for (int i = 0; i <= 100001; i++)
		if (truth[i] == i)
			ans = i;

	printf("%d\n", ans);

	return 0;
}