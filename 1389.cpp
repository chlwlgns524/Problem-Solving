#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

void bfs(int root);
vector<vector<int>> relation;
vector<int> kevinBaconNumber;
int level[MAX + 1];
int n, m;
/*
* 케빈 베이컨의 6단계 법칙
*/
int main() {
	scanf("%d %d", &n, &m);

	relation.resize(n + 1);
	kevinBaconNumber.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;

		scanf("%d %d", &from, &to);
		relation[from].push_back(to);
		relation[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);

		for (int j = 1; j <= n; j++)
			level[j] = 0;
	}
	
	int minimumNode = 1;
	int minimum = kevinBaconNumber[1];
	for (unsigned int currentNode = 2; currentNode < kevinBaconNumber.size(); currentNode++)
		if (kevinBaconNumber[currentNode] < minimum) {
			minimum = kevinBaconNumber[currentNode];
			minimumNode = currentNode;
		}
	printf("%d\n", minimumNode);
	
	return 0;
}

void bfs(int root) {
	queue<int> q;

	q.push(root);
	level[root] = 1;
	while (!q.empty()) {
		int currentNode = q.front();
		
		for (unsigned int i = 0; i < relation[currentNode].size(); i++) {
			int nextNode = relation[currentNode][i];
			if (!level[nextNode]) {
				q.push(nextNode);
				level[nextNode] = level[currentNode] + 1;
				kevinBaconNumber[root] += level[nextNode] - 1;
			}
		}

		q.pop();
	}
}