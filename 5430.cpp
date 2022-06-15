#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
* AC
* (R������ �����Ҷ����� �����̳��� ������ reverse�ϰ� �Ǹ� �ð��ʰ��� �߻��Ѵ�.
* ���� R������ ������ �� �����̳ʿ� ����ִ� ��� ���Ҹ� reverse�ϴ� ���� �ƴ϶� 
* �ܼ��� �����̳��� �ε��� ���� ���⸸�� ����Ͽ� ������ �ذ��Ѵ�.)
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