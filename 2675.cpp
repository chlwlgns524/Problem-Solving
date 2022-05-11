#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX_LEN 20

using namespace std;
/*
* 문자열 반복
*/
int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		char str[MAX_LEN + 1];
		int n;

		scanf("%d", &n);
		getchar();

		scanf("%s", &str);

		for (int i = 0; str[i] != '\0'; i++)
			for (int j = 0; j < n; j++)
				printf("%c", str[i]);
		puts("");
	}

	return 0;
}