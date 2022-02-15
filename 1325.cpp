#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

void dfs(int from);
vector<int> infect[MAX + 1];
int numberOfInfection[MAX + 1];
bool visited[MAX + 1];
int n, m;
int infected;
/*
* 효율적인 해킹
*/
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &to, &from);
		infect[from].push_back(to);
	}

	int maximum = -1;
	for (int i = 1; i <= n; i++) {
		infected = 0;
		dfs(i);
		numberOfInfection[i] = infected;
		if (infected > maximum) maximum = infected;

		for (int j = 1; j <= n; j++)
			visited[j] = false;
	}

	for (int i = 1; i <= n; i++)
		if (numberOfInfection[i] == maximum) printf("%d ", i);

	return 0;
}

void dfs(int from) {
	visited[from] = true;
	infected++;

	for (unsigned int i = 0; i < infect[from].size(); i++) {
		int nextComputer = infect[from][i];

		if (!visited[nextComputer])
			dfs(nextComputer);
	}
}