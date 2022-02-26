#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
vector<vector<pair<int, int>>> road(20000 + 1);
vector<int> dist(20000 + 1, INF);
int N, D;
/*
* 지름길
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		int from, to, d;		
		cin >> from >> to >> d;

		// 문제에서 고속도로를 역주행할 수 없다고 했으므로 지름길에 연결된 지점이 목적지를
		// 넘어 선다면 해당 정보를 버린다. 또한 지름길의 길이가 지름길의 시작 지점부터
		// 도착 지점까지 지름길을 안 탔을 경우의 길이보다 크면 의미가 없으므로 해당 정보를 버린다.
		if (to <= D && d < to - from)
			road[from].push_back({ to, d });
	}

	dist[0] = 0;
	for (int here = 0; here <= D; here++) {
		// 현재 위치에서 연결된 지름길이 존재할 경우 경로의 길이 갱신
		for (int j = 0; j < road[here].size(); j++) {
			int to = road[here][j].first;
			int d = road[here][j].second;
						
			dist[to] = min(dist[to], dist[here] + d);
		}

		// 현재 위치에서 바로 다음 위치로 갈 경우 기존에 지름길을 통해 갱신된 길이 정보가
		// 존재할 수 있으므로 값을 비교 후 최솟값을 저장한다.
		dist[here + 1] = min(dist[here + 1], dist[here] + 1);
	}

	cout << dist[D];

	return 0;
}