#include <iostream>
using namespace std;
/*
* ¾à¼ö
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, min = 1000001, max = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		min = num < min ? num : min;
		max = num > max ? num : max;
	}

	cout << min * max;

	return 0;
}