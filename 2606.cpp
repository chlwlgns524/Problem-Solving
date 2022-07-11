#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int NUMBER_OF_COMPUTERS = 100;

void dfs(int start);
vector<int> graph[NUMBER_OF_COMPUTERS + 1];
bool visited[NUMBER_OF_COMPUTERS + 1];
/*
* 바이러스
* (Depth First Search를 이용한 풀이)
*/
int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(1);

	int infected = 0;
	for (int i = 1; i <= NUMBER_OF_COMPUTERS; i++)
		if (visited[i]) infected++;

	printf("%d\n", infected - 1);

	return 0;
}

void dfs(int start) {
	int current = start;
	visited[current] = true;
	for (unsigned int i = 0; i < graph[current].size(); i++) {
		int next = graph[current][i];
		
		if (!visited[next]) 
			dfs(next);
	}
}