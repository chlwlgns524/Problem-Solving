#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
/*
* ÇÑ¼ö
*/
int main() {
    int n, ans = 0;

    scanf("%d", &n);

    if (0 < n && n < 100)
        ans = n;
    else if (n < 111)
        ans = 99;
    else if (n >= 111) {
        if (n == 1000) n = 999;
        ans = 99;

        for (int i = 111; i <= n; i++) {
            string num = to_string(i);
            
            if ((num[1] - num[0]) == (num[2] - num[1]))
                ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}