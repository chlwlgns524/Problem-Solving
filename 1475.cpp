#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> numberSet;
/*
* 방 번호
* (비트마스크를 이용한 풀이)
*/
int main() {
	string number;

	cin >> number;
	numberSet.push_back((1 << 10) - 1);
	for (unsigned int i = 0; i < number.length(); i++) {
		char ch = number[i];

		unsigned int j = 0;
		for (; j < numberSet.size(); j++) {
			if (numberSet[j] & (1 << (ch - '0'))) {
				numberSet[j] ^= (1 << (ch - '0'));
				break;
			}
			else {
				if (ch == '6' && (numberSet[j] & (1 << 9))) {
					numberSet[j] ^= (1 << 9);
					break;
				}
				else if (ch == '9' && (numberSet[j] & (1 << 6))) {
					numberSet[j] ^= (1 << 6);
					break;
				}
			}
		}

		if (j == numberSet.size()) {
			numberSet.push_back((1 << 10) - 1);
			numberSet[numberSet.size() - 1] ^= (1 << (ch - '0'));
		}
	}
	printf("%d\n", (int)numberSet.size());

	return 0;
}