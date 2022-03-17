#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

typedef long long int ll;

int num[10];
bool picked[10];
char sign[9];
ll minAns = LLONG_MAX, maxAns = LLONG_MIN;
int k;

bool isRight(int left, char ch, int right) {
	return ch == '<' ? left < right : left > right;
}

void go(int depth) {
	if (depth == k) {
		ll n = 0;
		for (int i = k, j = 0; i >= 0; i--)
			n += (ll)(num[i] * pow(10, j++));

		minAns = n < minAns ? n : minAns;
		maxAns = n > maxAns ? n : maxAns;
	}

	for (int i = 0; i < 10; i++) {
		if (!picked[i] && isRight(num[depth], sign[depth], i)) {
			picked[i] = true;
			num[depth + 1] = i;
			go(depth + 1);
			picked[i] = false;
		}
	}
}
/*
* ºÎµîÈ£
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	
	for (int i = 0; i < k; i++)
		cin >> sign[i];
	
	for (int i = 0; i < 10; i++) {
		picked[i] = true;
		num[0] = i;
		go(0);
		picked[i] = false;
	}

	string m = to_string(minAns);

	cout << maxAns << "\n";
	cout << (m.length() == (k + 1) ? m : "0" + m) << "\n";

	return 0;
}