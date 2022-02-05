#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* ¸·´ë±â
*/
int main() {
	int x, stick, cnt = 0;
	scanf("%d", &x);
	for (stick = (1 << 6); stick > 0; stick--)
		if (stick == x) break;
	
	for (int i = 0; i < 7; i++)
		if (stick & (1 << i)) cnt++;
	printf("%d\n", cnt);

	return 0;
}