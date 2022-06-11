#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define DIGIT 3

using namespace std;

int pow(int base, int exp);
/*
* »ó¼ö
*/
int main() {
    char a[DIGIT + 1], b[DIGIT + 1];
    int numA = 0, numB = 0;

    scanf("%s %s", &a, &b);

    for (int i = DIGIT - 1; i >= 0; i--) {
        numA += (a[i] - '0') * pow(10, i);
        numB += (b[i] - '0') * pow(10, i);
    }
    
    printf("%d\n", numA > numB ? numA : numB);

    return 0;
}

int pow(int base, int exp) {
    if (exp == 0)
        return 1;

    return base * pow(base, exp - 1);
}