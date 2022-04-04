#include <iostream>
using namespace std;

const int LIMIT = 10000;

int a[LIMIT];

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool prev_permutation(int* a, int* b) {
	int lastIdx = (b - a) - 1;
	int i = lastIdx;
	while (i > 0 && a[i - 1] <= a[i]) i--;

	if (i == 0) return false;

	int j = lastIdx;
	while (a[i - 1] <= a[j]) j--;

	swap(a[i - 1], a[j]);

	j = lastIdx;
	while (i < j)
		swap(a[i++], a[j--]);

	return true;
}
/*
* 이전 순열
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> a[i];

	if (prev_permutation(a, a + N))
		for (int i = 0; i < N; i++)
			cout << a[i] << " ";
	else
		cout << -1;
	
	return 0;
}