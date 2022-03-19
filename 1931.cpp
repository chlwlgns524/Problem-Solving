#include <iostream>
#include <vector>
using namespace std;

struct Meeting {
	int start;
	int end;
};

typedef bool(*end_ascending)(const Meeting&, const Meeting&);

vector<Meeting> v(100000), temp(100000);
int n, last, ans;

bool cmp(const Meeting& a, const Meeting& b);
void partition(int start, int end, end_ascending fptr);
void mergeSort(int start, int middle, int end, end_ascending fptr);
/*
* 회의실 배정
* (대표적인 Greedy Algorithm 문제 유형. 끝나는 시간을 기준으로 회의 스케쥴을 정렬한 뒤에
* 가능한 회의의 최대 개수를 구한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		Meeting m;
		cin >> m.start >> m.end;
		v[i] = m;
	}

	partition(0, n - 1, cmp);

	for (int i = 0; i < n; i++)
		if (v[i].start >= last) {
			last = v[i].end;
			ans++;
		}
	cout << ans;

	return 0;
}

bool cmp(const Meeting& a, const Meeting& b) {
	if (a.end == b.end)
		return a.start < b.start;
	else
		return a.end < b.end;
}

void partition(int start, int end, end_ascending fptr) {
	if (start < end) {
		int middle = (start + end) / 2;
		partition(start, middle, fptr);
		partition(middle + 1, end, fptr);
		mergeSort(start, middle, end, fptr);
	}
}

void mergeSort(int start, int middle, int end, end_ascending fptr) {
	for (int i = start; i <= end; i++)
		temp[i] = v[i];

	int part1 = start;
	int part2 = middle + 1;
	int index = start;
	while (part1 <= middle && part2 <= end) {
		if (fptr(temp[part1], temp[part2]))
			v[index++] = temp[part1++];
		else
			v[index++] = temp[part2++];
	}
	while (part1 <= middle) v[index++] = temp[part1++];
}