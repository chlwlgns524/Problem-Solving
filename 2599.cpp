#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
/*
* 짝 정하기
* (DFS로 푸는데 실패하여 수학적인 관계로 풀이하였음.)
*/
int main() {
	vector<pair<int, int>> student(3);
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &student[i].first, &student[i].second);

	for (int i = 0; i <= student[0].first; i++) {
		int ab = i;
		int ac = student[0].first - ab;
		int bc = student[2].second - ac;
		int ba = student[1].first - bc;
		int ca = student[0].second - ba;
		int cb = student[2].first - ca;

		if (ab >= 0 && ac >= 0 && ba >= 0 && bc >= 0 && ca >= 0 && cb >= 0) {
			printf("1\n");
			printf("%d %d\n%d %d\n%d %d\n", ab, ac, ba, bc, ca, cb);
			return 0;
		}
	}
	printf("0\n");

	return 0;
}