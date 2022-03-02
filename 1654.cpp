#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
int l[10000];
int n, k;
/*
* 랜선 자르기
* (Binary Search 기법을 차용한 Parametric Search 풀이.)
*/
int main() {
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
        scanf("%d", &l[i]);

    sort(l, l + k);

    ll left = 1;
    ll right = l[k - 1];

    ll ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;

        ll cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += (l[i] / mid);

        if (cnt >= n) {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    printf("%d\n", (int)ans);

    return 0;
}