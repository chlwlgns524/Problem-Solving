#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define SCALE_NUMBER 8

using namespace std;
/*
* À½°è
*/
int main() {
    string result = "mixed";
    int scale[SCALE_NUMBER];

    for (int i = 0; i < SCALE_NUMBER; i++)
        scanf("%d", &scale[i]);

    int i;
    if (scale[0] == 1) {
        for (i = 1; i < SCALE_NUMBER; i++)
            if (scale[i] != i + 1)
                break;

        if (i == 8) result = "ascending";
    }
    else if (scale[0] == 8) {
        for (i = 1; i < SCALE_NUMBER; i++)
            if (scale[i] != SCALE_NUMBER - i)
                break;

        if (i == 8) result = "descending";
    }
    cout << result << endl;

    return 0;
}