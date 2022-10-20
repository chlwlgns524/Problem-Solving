#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXIMUM_NUMBER 100000
using namespace std;

int dfs(int first, int currentNode, int count);
int linked[MAXIMUM_NUMBER + 1];
int root[MAXIMUM_NUMBER + 1];
int visited[MAXIMUM_NUMBER + 1];
/*
* ер га╥на╖ф╝
*/
int main() {
	int t;
	
	scanf("%d", &t);
	while (t--) {
		int n;

		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &linked[i]);

		int belonged = 0;
		for (int i = 1; i <= n; i++)
			if (!visited[i]) belonged += dfs(i, i, 1);
		printf("%d\n", n - belonged);

		for (int i = 1; i <= n; i++) {
			linked[i] = 0;
			root[i] = 0;
			visited[i] = 0;
		}
	}

	return 0;
}

int dfs(int first, int currentNode, int count) {
	if (visited[currentNode]) {
		if (root[currentNode] != first) return 0;

		return count - visited[currentNode];
	}

	visited[currentNode] = count;
	root[currentNode] = first;

	return dfs(first, linked[currentNode], count + 1);
}