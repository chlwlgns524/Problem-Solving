#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
/*
* 평균은 넘겠지
*/
int main() {
	int c;

	scanf("%d", &c);
	while (c--) {
		int n;
	
		scanf("%d", &n);

		vector<int> score(n);

		double sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}

		double average = sum / n;
		int aboveAverage = 0;

		for (int i = 0; i < n; i++)
			if (score[i] > average)
				aboveAverage++;

		printf("%.3f%%\n", (double)aboveAverage / n * 100);
	}

	return 0;
}