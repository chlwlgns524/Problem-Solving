#include <iostream>
using namespace std;
/*
* 돌 게임
* (한 번의 턴에서 무조건 홀수개의 돌만 가져갈 수 있다는 사실에 주목해 본다.)
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