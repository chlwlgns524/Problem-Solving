#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
/*
* ЦђБе
*/
int main() {
	int numberOfScores;

	scanf("%d", &numberOfScores);

	vector<int> score(numberOfScores);
	int max;

	for (int i = 0; i < numberOfScores; i++)
		scanf("%d", &score[i]);

	max = score[0];
	for (int i = 1; i < numberOfScores; i++)
		if (score[i] > max)
			max = score[i];
	
	double sum = 0;
	for (int i = 0; i < numberOfScores; i++)
		sum += ((double)score[i] / max) * 100;

	printf("%f\n", sum / numberOfScores);

	return 0;
}