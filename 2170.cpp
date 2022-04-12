#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> line;
bool ascending(pair<int, int> p1, pair<int, int>p2) {
	return p1.first < p2.first;
}

int maxInt(int a, int b) {
	return (a > b ? a : b);
}
/*
* ¼± ±ß±â
* (Sweeping Algorithm.)
*/
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	line.resize(N);

	for (int i = 0; i < N; i++)
		cin >> line[i].first >> line[i].second;

	sort(line.begin(), line.end(), ascending);

	int left = line[0].first, right = line[0].second, ans = 0;
	for (int i = 1; i < N; i++) {
		if (line[i].first <= right)
			right = maxInt(line[i].second, right);
		else {
			ans += right - left;
			left = line[i].first;
			right = line[i].second;
		}
	}
	ans += (right - left);
	cout << ans;

	return 0;
}