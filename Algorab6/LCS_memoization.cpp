#include <iostream>
#include <cstring>
using namespace std;

int L[102][102];

int LCS(char s[], char t[], int m, int n)
{
    // 두 문자열의 길이가 하나라도 0인 경우
    if (m == 0 || n == 0) {
        L[m][n] = 0;
        return L[m][n];
    }
    else {
        // L table에 기록이 되어 있으면 메모된 값을 반환
        if (L[m][n] != -1) {
            return L[m][n];
        }
        // 두 문자열의 맨 마지막 원소가 같을 경우(LCS에 포함)
        if (s[m - 1] == t[n - 1]) {
            L[m][n] = LCS(s, t, m - 1, n - 1) + 1;
        }
        // 두 문자열의 맨 마지막 원소가 다른 경우
        else if (s[m - 1] != t[n - 1]) {
            L[m][n] = max(LCS(s, t, m - 1, n), LCS(s, t, m, n - 1));
        }
        return L[m][n];
    } 
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    char s[102], t[102];
    
    for (int i = 0; i < numTestCase; i++) {
        cin >> s >> t;

        int slen = strlen(s);
        int tlen = strlen(t);

        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++)
                L[i][j] = -1;
        }

        cout << LCS(s, t, slen, tlen) << endl;
    }
    return 0;
}