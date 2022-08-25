#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

inline int intAbs(int a, int b);
/*
* ½´ÆÛ ¸¶¸®¿À
*/
int main() {
	int ans = 0;
	int mushroom[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", (mushroom + i));

	for (int i = 0; i < 10; i++) {
		int score = 0;
		for (int j = 0; j < i + 1; j++)
			score += mushroom[j];
		if ((intAbs(100, score) < intAbs(100, ans)) ||
			(intAbs(100, score) == intAbs(100, ans) && score > ans))
			ans = score;
	}
	printf("%d\n", ans);

	return 0;
}

inline int intAbs(int a, int b) {
	return ((a - b < 0) ? b - a : a - b);
}