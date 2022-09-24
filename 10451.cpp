#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_NUM 1000
using namespace std;

void dfs(int currentNode);
int graph[MAX_NUM + 1];
bool visited[MAX_NUM + 1];
int numberOfCycles;
/*
* 순열 사이클
*/
int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n;

		scanf("%d", &n);
		for (int node = 1; node <= n; node++)
			scanf("%d", &graph[node]);

		for (int node = 1; node <= n; node++)
			if (!visited[node])
				dfs(node);
		printf("%d\n", numberOfCycles);

		numberOfCycles = 0;
		for (int node = 1; node <= n; node++)
			visited[node] = false;
	}

	return 0;
}

void dfs(int currentNode) {
	visited[currentNode] = true;

	int nextNode = graph[currentNode];
	if (visited[nextNode]) {
		numberOfCycles++;
		return;
	}
	else
		dfs(nextNode);
}