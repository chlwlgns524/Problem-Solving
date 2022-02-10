#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define ALPHA_LEN 26

using namespace std;

char toUpper(char ch);

int alpha[ALPHA_LEN];
/*
* 단어 공부
*/
int main() {
    string str;
    
    cin >> str;

    for (int i = 0; str[i]; i++)
        alpha[toUpper(str[i]) - 'A']++;

    int max = alpha[0];
    int maxIndex = 0;
    for (int i = 1; i < ALPHA_LEN; i++)
        if (alpha[i] > max) {
            max = alpha[i];
            maxIndex = i;
        }

    int numberOfMax = 0;
    for (int i = 0; i < ALPHA_LEN; i++)
        if (alpha[i] == max)
            numberOfMax++;

    printf("%c", numberOfMax > 1 ? '?' : 'A' + maxIndex);

    return 0;
}

char toUpper(char ch) {
    return ('a' <= ch && ch <= 'z') ? ('A' + (ch - 'a')) : ch;
}