#include <iostream>
using namespace std;
/*
* ī�� �޷�
* (y�� N�� ���� ��츦 ����ؼ� x�� y�� 1�� ���� �� �����Ѵ�.)
*/
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		x--;
		y--;
		bool found = false;
		for (int k = x; k < M * N; k += M) {
			if (k % N == y) {
				found = true;
				cout << k + 1<< "\n";
				break;
			}
		}
		if (!found) cout << "-1\n";
	}

	return 0;
}