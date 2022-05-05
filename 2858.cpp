#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int L, W;
inline void getTile(int& rTile, int& bTile);
/*
* 기숙사 바닥
* (문제에서 R과 B의 범위가 각각 8 ≤ R ≤ 5000, 1 ≤ B ≤ 2,000,000으로 설정되어 있다.
* 이때, R의 하한갯수인 8과 B의 하한갯수인 1이 나올 수 있는 경우는 R = 3, B = 3일때이다.
* 즉 방의 크기가 3X3 정사각형일때이다. 따라서 루프에서 L과 W의 시작 지점을 각각 3으로
* 잡고, W는 L의 크기를 넘을 수 없으므로 W의 상한갯수는 L로 설정한다.)
*/
int main() {
	int R, B;
	scanf("%d %d", &R, &B);

	for (L = 3;; L++) {
		for (W = 3; W <= L; W++) {
			int redTile, brownTile;
			getTile(redTile, brownTile);
			if (redTile == R && brownTile == B) {
				printf("%d %d\n", L, W);
				return 0;
			}
		}
	}
}

inline void getTile(int& rTile, int& bTile) {
	rTile = (L * 2) + (W - 2) * 2;
	bTile = L * W - rTile;
}