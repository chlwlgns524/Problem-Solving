#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

inline bool isHour(int hh) { return 1 <= hh && hh <= 12; }
inline bool isMinute(int mm) { return 0 <= mm && mm <= 59; }
inline bool isSecond(int ss) { return 0 <= ss && ss <= 59; }
void permutation(int toPick);
int d[3], ans;
/*
* 타임머신
*/
int main() {
	char c;
	scanf("%d%c%d%c%d", &d[0], &c, &d[1], &c, &d[2]);
	permutation(0);
	printf("%d\n", ans);

	return 0;
}

void permutation(int toPick) {
	if (toPick == 3) {
		if (isHour(d[0]) && isMinute(d[1]) && isSecond(d[2])) ans++;
	}
	else {
		for (int i = toPick; i < 3; i++) {
			swap(d[toPick], d[i]);
			permutation(toPick + 1);
			swap(d[toPick], d[i]);
		}
	}
}