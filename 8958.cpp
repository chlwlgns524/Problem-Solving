#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
/*
* OXÄûÁî
*/
int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int sum = 0;
		int score = 0;
		string str;

		cin >> str;

		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == 'O') {
				score++;
				sum += score;
			}
			else
				score = 0;

		printf("%d\n", sum);
	}

	return 0;
}