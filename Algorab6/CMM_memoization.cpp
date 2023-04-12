#include <iostream>
using namespace std;

int dp[102][102];

int CMM(int matrix[], int start, int end)
{
    if (start == end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    dp[start][end] = 2147483647;

    for (int k = start; k < end; k++) {
        dp[start][end] = min(dp[start][end], (CMM(matrix, start, k)
            + CMM(matrix, k + 1, end)
            + matrix[start - 1] * matrix[k] * matrix[end]));
    }
    return dp[start][end];
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    int mat[100] = { 0, };

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;

        for (int i = 0; i <= num; i++)
            cin >> mat[i];

        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++)
                dp[i][j] = -1;
        }

        cout << CMM(mat, 1, num) << endl;
    }

    return 0;
}