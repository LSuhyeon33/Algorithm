#include <iostream>
#include <cstring>
using namespace std;

void add0(char v[], int len)
{
    for (int i = len; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = 0;
}

int LCS(char s[], char t[], int m, int n)
{
    // 두 문자열의 길이가 하나라도 0인 경우
    if (m == 0 || n == 0) {
        return 0;
    }

    // 두 문자열의 맨 마지막 원소가 같을 경우(LCS에 포함)
    if (s[m] == t[n]) {
        return LCS(s, t, m - 1, n - 1) + 1;
    }
    // 두 문자열의 맨 마지막 원소가 다른 경우
    else if (s[m] != t[n]) {
        return max(LCS(s, t, m - 1, n), LCS(s, t, m, n - 1));
    }
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        char s[12], t[12];
        cin >> s >> t;

        int slen = strlen(s);
        int tlen = strlen(t);

        add0(s, slen);
        add0(t, tlen);

        cout << LCS(s, t, slen, tlen) << endl;
    }
    return 0;
}