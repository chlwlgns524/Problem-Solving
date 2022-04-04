#include <iostream>
#define LIMIT 8
using namespace std;

int picked[LIMIT];
bool isPicked[LIMIT];
int N;

void perm(int depth) {
	if (depth == N) {
		for (int i = 0; i < N; i++)
			cout << picked[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!isPicked[i]) {
			isPicked[i] = true;
			picked[depth] = i + 1;
			perm(depth + 1);
			isPicked[i] = false;
		}
	}
}
/*
* 모든 순열
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;

	perm(0);
	
	return 0;
}