#include <iostream>
#include <vector>
using namespace std;
/*
* 연속부분최대곱
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	double ans = 0;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++)

		cin >> v[i];
	for (int i = 1; i < n; i++)
		v[i] = max(v[i - 1] * v[i], v[i]);
	for (int i = 0; i < n; i++)
		if (v[i] > ans) ans = v[i];

	cout.setf(ios::fixed);
	cout.precision(3);
	cout << ans;

	return 0;
}