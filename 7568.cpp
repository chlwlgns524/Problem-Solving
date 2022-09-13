#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 50
using namespace std;

struct Person {
	int weight;
	int height;
	int place;
};

Person p[MAX];
int pick[2];
int n;
/*
* µ¢Ä¡
*/
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].weight, &p[i].height);

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (p[i].weight > p[j].weight && p[i].height > p[j].height) p[j].place++;
			if (p[i].weight < p[j].weight && p[i].height < p[j].height) p[i].place++;
		}

	for (int i = 0; i < n; i++)
		printf("%d ", p[i].place + 1);
	
	return 0;
}