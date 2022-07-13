#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int dfs(int currentMember, int level);
vector<int> parent;
bool visited[MAX + 1];
int level[MAX + 1];
/*
* ÃÌ¼ö°è»ê
*/
int main() {
	int n, from, to, m;

	scanf("%d %d %d %d", &n, &from, &to, &m);
	parent.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		parent[y] = x;
	}

	dfs(from, 0);
	int ans = dfs(to, 0);
	printf("%d\n", ans);

	return 0;
}

int dfs(int currentMember, int currentLevel) {
	if (visited[currentMember])
		return level[currentMember] + currentLevel;

	visited[currentMember] = true;
	level[currentMember] = currentLevel;
	if (!parent[currentMember])
		return -1;
	else
		return dfs(parent[currentMember], currentLevel + 1);
}