#include <iostream>
#include <string>
using namespace std;

int parseInt(string strNum) {
	int res = 0, digit = 1;

	for (int i = strNum.size() - 1; i >= 0; i--, digit *= 10)
		res += (strNum[i] - '0') * digit;

	return res;
}

bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}
/*
* ÀÒ¾î¹ö¸° °ýÈ£
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string input;
	cin >> input;
	
	bool minus = false;
	int i = 0, ans = 0, size = input.size();
	while(i < size) {
		string num;
		while (i < size && isDigit(input[i]))
			num.push_back(input[i++]);

		ans += minus ? -parseInt(num) : parseInt(num);

		if (i < size && input[i] == '-')
			minus = true;
		i++;
	}
	cout << ans;

	return 0;
}