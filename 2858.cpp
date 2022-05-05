#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int L, W;
inline void getTile(int& rTile, int& bTile);
/*
* ����� �ٴ�
* (�������� R�� B�� ������ ���� 8 �� R �� 5000, 1 �� B �� 2,000,000���� �����Ǿ� �ִ�.
* �̶�, R�� ���Ѱ����� 8�� B�� ���Ѱ����� 1�� ���� �� �ִ� ���� R = 3, B = 3�϶��̴�.
* �� ���� ũ�Ⱑ 3X3 ���簢���϶��̴�. ���� �������� L�� W�� ���� ������ ���� 3����
* ���, W�� L�� ũ�⸦ ���� �� �����Ƿ� W�� ���Ѱ����� L�� �����Ѵ�.)
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