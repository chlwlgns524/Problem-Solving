#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 2147483647;
vector<vector<pair<int, int>>> adjList;
int dist[20001];
int V, E, start;

void init() {
	adjList.resize(V + 1);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		adjList[from].push_back({ cost, to });
	}
}

void dijkstra() {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();

		for (int i = 0, size = adjList[here].size(); i < size; i++) {
			int next = adjList[here][i].second;
			int cost = adjList[here][i].first;
			if (dist[next] > dist[here] + cost) {
				dist[next] = dist[here] + cost;
				pq.push({ -dist[next], next });
			}
		}
	}
}
/*
* 최단경로
* (Dijkstra 알고리즘을 이용한 풀이.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> V >> E >> start;
	init();
	dijkstra();

	for (int i = 1; i <= V; i++)
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";

	return 0;
}