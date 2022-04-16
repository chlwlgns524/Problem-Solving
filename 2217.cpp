#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
* ทฮวม
*/
int main() {
	int n, max = 0;
	
	scanf("%d", &n);
	vector<int> rope(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &rope[i]);

	sort(rope.begin(), rope.end());
	reverse(rope.begin(), rope.end());
	
	for (int i = 0; i < n; i++)
		if (rope[i] * (i + 1) > max) 
			max = rope[i] * (i + 1);

	printf("%d\n", max);

	return 0;
}