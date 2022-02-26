#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
vector<vector<pair<int, int>>> road(20000 + 1);
vector<int> dist(20000 + 1, INF);
int N, D;
/*
* ������
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		int from, to, d;		
		cin >> from >> to >> d;

		// �������� ��ӵ��θ� �������� �� ���ٰ� �����Ƿ� �����濡 ����� ������ ��������
		// �Ѿ� ���ٸ� �ش� ������ ������. ���� �������� ���̰� �������� ���� ��������
		// ���� �������� �������� �� ���� ����� ���̺��� ũ�� �ǹ̰� �����Ƿ� �ش� ������ ������.
		if (to <= D && d < to - from)
			road[from].push_back({ to, d });
	}

	dist[0] = 0;
	for (int here = 0; here <= D; here++) {
		// ���� ��ġ���� ����� �������� ������ ��� ����� ���� ����
		for (int j = 0; j < road[here].size(); j++) {
			int to = road[here][j].first;
			int d = road[here][j].second;
						
			dist[to] = min(dist[to], dist[here] + d);
		}

		// ���� ��ġ���� �ٷ� ���� ��ġ�� �� ��� ������ �������� ���� ���ŵ� ���� ������
		// ������ �� �����Ƿ� ���� �� �� �ּڰ��� �����Ѵ�.
		dist[here + 1] = min(dist[here + 1], dist[here] + 1);
	}

	cout << dist[D];

	return 0;
}