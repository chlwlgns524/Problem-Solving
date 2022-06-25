#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
* 归汲 傍林客 老蚌 抄里捞
*/
int main() {
	int dwarf[9], sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", (dwarf + i));
		sum += dwarf[i];
	}

	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 9; j++)
			if (sum - dwarf[i] - dwarf[j] == 100) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j) printf("%d\n", dwarf[k]);
				return 0;
			}
}