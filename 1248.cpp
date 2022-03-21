#include <iostream>
#include <vector>
using namespace std;

int N;
bool found;
char sign[10][10];
vector<int> v;

bool isPossible(int idx) {
	int sum = 0;
	
	for (int i = idx; i >= 0; i--) {
		sum += v[i];
		if (sign[i][idx] == '+' && sum <= 0) return false;
		if (sign[i][idx] == '-' && sum >= 0) return false;
		if (sign[i][idx] == '0' && sum != 0) return false;
	}

	return true;
}

void solve(int idx) {
	if (idx == N) {
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
		found = true;
		return;
	}

	for (int i = -10; !found && i <= 10; i++) {
		v.push_back(i);
		if (isPossible(idx))
			solve(idx + 1); 
		v.pop_back();
	}
}
/*
* 맞춰봐
* (백트래킹을 활용한 풀이. 브루트 포스 방식으로 풀면 시간 초과가 발생한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			cin >> sign[i][j];

	solve(0);

	return 0;
}