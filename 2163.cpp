#include <iostream>
using namespace std;
/*
* ���ݸ� �ڸ���
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int row, col, ans;
	
	cin >> row >> col;
	
	ans = (row - 1) + (col - 1) * row;
	cout << ans;

	return 0;
}