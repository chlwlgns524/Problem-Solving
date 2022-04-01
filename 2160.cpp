#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
const int MAX = 50;
const int ROW = 5;
const int COLUMN = 7;
char picture[MAX][ROW][COLUMN];
int n;
int picked[2];
int ans = 36;
int p1;
int p2;

void go(int toPick, int prev);
inline int compare(int a, int b);
/*
* 그림 비교
*/
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 7; k++)
				scanf(" %c", &picture[i][j][k]);

	go(0, -1);
	printf("%d %d\n", p1, p2);
	
	return 0;
}

void go(int toPick, int prev) {
	if (toPick == 2) {
		int temp = compare(picked[0], picked[1]);
		if (temp < ans) {
			ans = temp;
			p1 = picked[0] + 1;
			p2 = picked[1] + 1;
		}
		return;
	}
	
	for (int i = prev + 1; i < n; i++) {
		picked[toPick] = i;
		go(toPick + 1, i);
	}
}

inline int compare(int a, int b) {
	int result = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
			if (picture[a][i][j] != picture[b][i][j]) result++;
	return result;
}