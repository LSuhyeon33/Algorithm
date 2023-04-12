#include <iostream>
#include <cstring>
using namespace std;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void flipover(char str[], int first, int last)
{
    swap(str[first], str[last]);
    if (first + 1 < last - 1)
        flipover(str, first + 1, last - 1);
    else
        cout << str << endl;
}

int main(void)
{
    int numTestCase;
    cin >> numTestCase;

    char str[102] = { 0x00, };
    for (int i = 0; i < numTestCase; i++) {
        cin >> str;
        flipover(str, 0, strlen(str) - 1);
    }

    return 0;
}