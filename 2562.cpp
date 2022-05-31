#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define MAX 9

using namespace std;
/*
* ÃÖ´ñ°ª
*/
int main() {
	vector<int> v(MAX);
	int max, index;
	
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &v[i]);

		if (i == 0) {
			max = v[0];
			index = 0 + 1;
		}
		else
			if (v[i] > max) {
				max = v[i];
				index = i + 1;
			}	
	}

	printf("%d\n%d\n", max, index);

	return 0;
}