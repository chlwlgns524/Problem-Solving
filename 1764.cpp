#include <iostream>
#include <algorithm>
using namespace std;

template <typename Ty> 
int bianrySearch(Ty* arr, int low, int high, const Ty& target);
string unHeard[500000], unSeen[500000], both[500000];
/*
* µèº¸Àâ
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> unHeard[i];
	for (int i = 0; i < M; i++)
		cin >> unSeen[i];

	sort(unHeard, unHeard + N);
	sort(unSeen, unSeen + M);

	for (int i = 0; i < M; i++) {
		int index = bianrySearch(unHeard, 0, N - 1, unSeen[i]);
		if (index >= 0) {
			both[ans] = unHeard[index];
			ans++;
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < ans; i++)
		cout << both[i] << "\n";

	return 0;
}

template <typename Ty>
int bianrySearch(Ty* arr, int low, int high, const Ty& target) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (target < arr[mid])
			return bianrySearch(arr, low, mid - 1, target);
		else if (target > arr[mid])
			return bianrySearch(arr, mid + 1, high, target);
		else
			return mid;
	}
	return -1;
}