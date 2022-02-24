#include <iostream>
using namespace std;
/*
* 1
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;

	while (cin >> n) {
		int target = 1;
		int digit = 1;

		while (target) {
			if (target % n == 0)
				break;

			digit++;
			target = target * 10 + 1;
			target %= n;
		}

		cout << digit << "\n";
	}

	return 0;
}