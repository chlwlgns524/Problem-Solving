#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define MAX_LEN 1000000

using namespace std;
/*
* 단어의 개수
*/
int main() {
    char msg[MAX_LEN + 1];
    int numberOfWords = 1;

    cin.getline(msg, MAX_LEN + 1);

    for (int i = 0; msg[i]; i++)
        if (msg[i] == ' ')
            numberOfWords++;

    if (msg[0] == ' ') numberOfWords--;
    if (msg[strlen(msg) - 1] == ' ') numberOfWords--;
    
    printf("%d\n", numberOfWords);

    return 0;
}