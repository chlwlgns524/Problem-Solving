#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p);
vector<int> kmp(string t, string p);
/*
* 찾기
* (문제 자체가 KMP 알고리즘을 구현할 것을 요구한다.)
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string t, p; 
	getline(cin, t);
	getline(cin, p); 
	
	vector<int> finalAns = kmp(t, p);
	int len = (int)finalAns.size();
	
	cout << len << "\n";
	for (int i = 0; i < len; i++)
		cout << (finalAns[i] + 1) << " ";
	
	return 0;
}

vector<int> getPi(string p) {
	int len = (int)p.size();
	vector<int> pi(len, 0);

	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> kmp(string t, string p) {
	vector<int> ans;
	int n = (int)t.size(), m = (int)p.size();
	auto pi = getPi(p);

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && t[i] != p[j])
			j = pi[j - 1];
		if (t[i] == p[j]) {
			if (j == (m - 1)) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}

	return ans;
}