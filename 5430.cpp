#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
* AC
* (R연산을 수행할때마다 컨테이너의 값들을 reverse하게 되면 시간초과가 발생한다.
* 따라서 R연산을 수행할 때 컨테이너에 들어있는 모든 원소를 reverse하는 것이 아니라 
* 단순히 컨테이너의 인덱스 진행 방향만을 고려하여 문제를 해결한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string p, info;
		vector<int> v;
		
		cin >> p >> n >> info;

		if (n) {
			int index = 1;
			string num = "";

			while(1) {
				if (info[index] == ',') {
					v.push_back(stoi(num));
					num = "";
				}
				else if (info[index] == ']') {
					v.push_back(stoi(num));
					break;
				}
				else
					num += info[index];
				index++;
			}
		}

		bool isPositive = true, isError = false;
		int begin = 0, end = n;
		for (int i = 0; p[i]; i++) {
			if (p[i] == 'R')
				isPositive = !isPositive;
			else {
				if (begin < end) {
					if (isPositive)
						begin++;
					else
						end--;
				}
				else {
					isError = true;
					break;
				}
			}
		}

		if (isError)
			cout << "error\n";
		else {
			cout << "[";
			if (isPositive)
				for (int i = begin; i < end; i++)
					cout << v[i] << (i != end - 1 ? "," : "");
			else
				for (int i = end - 1; i >= begin; i--)
					cout << v[i] << (i != begin ? "," : "");
			cout << "]\n";
		}
	}
	
	return 0;
}