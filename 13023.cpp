#include <iostream>
#include <vector>
#define LIMIT 2000
using namespace std;

vector<vector<int>> rel;
bool isVisited[LIMIT];
bool found;
int N, M;

void dfs(int from, int depth) {
	if (depth == 4) {
		found = true;
		return;
	}

	for (int i = 0; !found && i < rel[from].size(); i++) {
		int to = rel[from][i];
		if (!isVisited[to]) {
			isVisited[to] = true;
			dfs(to, depth + 1);
			isVisited[to] = false;
		}
	}
}
/*
* ABCDE
* (인접 행렬로 문제 풀이를 하면 시간 초과가 발생한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	rel.resize(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		rel[x].push_back(y);
		rel[y].push_back(x);
	}

	for (int from = 0; !found && from < N; from++) {
		isVisited[from] = true;
		dfs(from, 0);
		isVisited[from] = false;
	}

	cout << (found == true ? 1 : 0);

	return 0;
}