#include <iostream>
#include <cstring>
using namespace std;

// L: s와 t의 LCS 길이를 저장한 table
// S: LCS를 구하기 위한 정보를 저장한 table
int L[101][101], S[101][101];

int LCS(char s[], char t[], int m, int n)
{
    // base case
    for (int i = 0; i <= m; i++) {
        L[i][0] = 0;
    }
    for (int i = 0; i <= n; i++) {
        L[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                if (L[i][j] == L[i][j - 1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void printLCS(char s[], char t[], int m, int n)
{
    if (m == 0 || n == 0)
        return;
    if (S[m][n] == 0) {
        printLCS(s, t, m - 1, n - 1);
        cout << s[m - 1];
    }
    else if (S[m][n] == 1)
        printLCS(s, t, m, n - 1);
    else if (S[m][n] == 2)
        printLCS(s, t, m - 1, n);
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    char s[101], t[101];

    for (int i = 0; i < numTestCase; i++) {
        cin >> s >> t;

        int slen = strlen(s);
        int tlen = strlen(t);

        cout << LCS(s, t, slen, tlen) << " ";
        printLCS(s, t, slen, tlen);
        cout << endl;
    }
    return 0;
}