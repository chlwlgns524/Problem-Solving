#include <iostream>
using namespace std;
/*
* �ٸ� ����
* (�ܼ��� Combination ����. �׷��� �ܼ��� ���丮�� ������ �����ϸ�
* ������ �߻��Ѵ�. ���� ���丮�� ������ ���� ���� �����ϴ� ���� ����.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int M, N, pick = 1, ans = 1;
		cin >> N >> M;
		while (pick <= N) {
			ans *= M;
			ans /= pick;
			M--;
			pick++;
		}
		cout << ans << "\n";
	}

	return 0;
}