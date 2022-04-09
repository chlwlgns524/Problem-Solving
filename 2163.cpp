#include <iostream>
using namespace std;
/*
* 초콜릿 자르기
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