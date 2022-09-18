#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define ALPHA_LEN 26

using namespace std;
/*
* ¾ËÆÄºª Ã£±â
*/
int main() {
    int alpha[ALPHA_LEN];
    string str;

    for (int i = 0; i < ALPHA_LEN; i++)
        alpha[i] = -1;

    cin >> str;

    for (int i = 0; str[i]; i++)
        if (alpha[str[i] - 'a'] == -1)
            alpha[str[i] - 'a'] = i;

    for (int i = 0; i < ALPHA_LEN; i++)
        printf("%d ", alpha[i]);
    puts("");

    return 0;
}