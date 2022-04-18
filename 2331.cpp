#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#define MAX_NUM 1000000
using namespace std;

void dfs(string d, int count);
int countCorrespondingTo[MAX_NUM];
bool visited[MAX_NUM];
int a;
int p;
/*
* 반복수열
*/
int main() {
	scanf("%d %d", &a, &p);

	dfs(to_string(a), 1);

	return 0;
}

void dfs(string d, int count) {
	if (visited[stoi(d)]) {
		printf("%d\n", countCorrespondingTo[stoi(d)] - 1);
		return;
	}

	visited[stoi(d)] = true;
	countCorrespondingTo[stoi(d)] = count;

	int sum = 0;
	for (unsigned int i = 0; i < d.length(); i++)
		sum += (int)pow(d[i] - '0', p);

	dfs(to_string(sum), count + 1);
}