#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

void dfs(int start);
void bfs(int start);
vector<int> graph[1001];
bool visited[1001];
/*
* DFS와 BFS
* (DFS의 경우는 stack과 recursion을 이용한 구현 모두를 포함)
*/
int main() {
	int n, m, v;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	puts("");
	memset(visited, 0, 1001 * sizeof(bool));
	bfs(v);

	return 0;
}

void dfs(int start) {
	if (visited[start])
		return;

	visited[start] = true;
	printf("%d ", start);
	for (int i = 0; i < graph[start].size(); i++)
		dfs(graph[start][i]);
}

void bfs(int start) {
	queue<int> q;

	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int currentVertex = q.front();
		printf("%d ", currentVertex);

		for (int i = 0; i < graph[currentVertex].size(); i++) {
			int nextVertex = graph[currentVertex][i];
			if (!visited[nextVertex]) {
				q.push(nextVertex);
				visited[nextVertex] = true;
			}
		}

		q.pop();
	}
}
/*
void dfs(int start) {
	stack<int> s;

	s.push(start);
	visited[start] = true;
	printf("%d ", start);
	while (!s.empty()) {
		int currentVertex = s.top();

		for (int i = 0; i < graph[currentVertex].size(); i++) {
			int nextVertex = graph[currentVertex][i];
			if (!visited[nextVertex]) {
				s.push(nextVertex);
				visited[nextVertex] = true;
				printf("%d ", nextVertex);
				break;
			}
			else if (i == graph[currentVertex].size() - 1)
				s.pop();
		}
	}
}
*/