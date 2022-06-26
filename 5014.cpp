#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int building[1000001];
/*
* 스타트링크
* (현재 위치도 도착의 대상이 될 수 있도록 최초 bfs 탐색을 시작하기 전에
* 현재 위치의 배열을 0으로 초기화시키고 나머지 위치들은 모두 -1로 초기화한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int total, cur, target, up, down;
	cin >> total >> cur >>  target >> up >> down;

	queue<int> q;
	memset(building, -1, sizeof(building));

	building[cur] = 0;
	q.push(cur);
	while (!q.empty()) {
		int from = q.front();
		q.pop();

		if (building[target] >= 0) {
			cout << building[target];
			return 0;
		}

		for (int to : {from + up, from - down}) {
			if (0 < to && to <= total && building[to] == -1) {
				building[to] = building[from] + 1;
				q.push(to);
			}
		}
	}

	cout << "use the stairs";
		
	return 0;
}