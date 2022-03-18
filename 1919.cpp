#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define ALPHA_LEN 26
using namespace std;

string str[2];
int alpha[2][ALPHA_LEN];
/*
* 애너그램 만들기
*/
int main() {
    cin >> str[0] >> str[1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < str[i].length(); j++)
            alpha[i][str[i][j] - 'a']++;

    int ans = 0;
    for (int i = 0; i < ALPHA_LEN; i++) {
        int d = alpha[0][i] - alpha[1][i];
        ans += d < 0 ? -d : d;
    }
    printf("%d\n", ans);

    return 0;
}