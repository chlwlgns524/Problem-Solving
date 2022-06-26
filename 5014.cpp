#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int building[1000001];
/*
* ��ŸƮ��ũ
* (���� ��ġ�� ������ ����� �� �� �ֵ��� ���� bfs Ž���� �����ϱ� ����
* ���� ��ġ�� �迭�� 0���� �ʱ�ȭ��Ű�� ������ ��ġ���� ��� -1�� �ʱ�ȭ�Ѵ�.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int total, cur, target, up, down;
	cin >> total >> cur >>  target >> up >> down;

	queue<int> q;
	memset(building, -1, sizeof(building));

	building[cur] = 0;
	q.push(cur);
	while (!q.empty()) {
		int from = q.front();
		q.pop();

		if (building[target] >= 0) {
			cout << building[target];
			return 0;
		}

		for (int to : {from + up, from - down}) {
			if (0 < to && to <= total && building[to] == -1) {
				building[to] = building[from] + 1;
				q.push(to);
			}
		}
	}

	cout << "use the stairs";
		
	return 0;
}