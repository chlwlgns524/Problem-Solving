#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
* 나는야 포켓몬 마스터 이다솜
* (STL의 map을 이용한 풀이. map의 내부 구현은 RED-BLACK TREE이다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	map<string, int> simap;
	map<int, string> ismap;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string poketmon;
		cin >> poketmon;
		simap[poketmon] = i;
		ismap[i] = poketmon;
	}

	while (M--) {
		string input;
		cin >> input;

		if ('0' <= input[0] && input[0] <= '9')
			cout << ismap[stoi(input)];
		else
			cout << simap[input];
		cout << "\n";
	}

	return 0;
}