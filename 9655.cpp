#include <iostream>
using namespace std;
/*
* �� ����
* (�� ���� �Ͽ��� ������ Ȧ������ ���� ������ �� �ִٴ� ��ǿ� �ָ��� ����.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cout << (N % 2 == 0 ? "CY" : "SK");

	return 0;
}