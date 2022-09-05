#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Pos {
	int x;
	int y;
};
Pos dial[10] = { {3, 1}, {0, 0}, {0, 1}, {0, 2}, 
	{1, 0}, {1, 1}, {1, 2},
	{2, 0}, {2, 1}, {2, 2} };
inline int effort(int d1, int d2);
/*
* 알람시계
*/
int main() {
	char c;
	int h, m;
	
	scanf("%d%c%d", &h, &c, &m);
	
	int ansH = h, ansM = m, minimum = 100;
	for (int hour = h; hour < 100; hour += 24)
		for (int minute = m; minute < 100; minute += 60) {
			int temp = effort(hour / 10, hour % 10) + effort(hour % 10, minute / 10) 
				+ effort(minute / 10, minute % 10);
			if (temp < minimum) {
				minimum = temp;
				ansH = hour;
				ansM = minute;
			}
		}
	printf("%02d:%02d", ansH, ansM);

	return 0;
}

inline int effort(int d1, int d2) {
	return abs(dial[d1].x - dial[d2].x) + abs(dial[d1].y - dial[d2].y);
}