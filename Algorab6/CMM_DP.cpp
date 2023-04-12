#include <iostream>
using namespace std;

int dp[102][102], P[102][102];

int CMM(int matrix[], int size) 
{
    // base case
    for (int i = 1; i <= size; i++)
        dp[i][i] = 0;

    for (int i = 1; i < size; i++) {
        for (int j = 1; j <= size - i; j++) {
            int k = j + i;
            dp[j][k] = 2147483647;

            for (int r = j; r < k; r++) {
                int value = dp[j][r] + dp[r + 1][k] + matrix[j - 1] * matrix[r] * matrix[k];

                if (dp[j][k] > value) {
                    dp[j][k] = value;
                    P[j][k] = r;
                }
            }
        }
    }
    return dp[1][size];
}

void printMat(int i, int j) 
{
    if (i == j)
        cout << "M" << i;
    else {
        int r = P[i][j];
        cout << "(";
        printMat(i, r);
        printMat(r + 1, j);
        cout << ")";
    }
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

        int min = CMM(mat, num);
        
        printMat(1, num);
        cout << endl;
        cout << min << endl;
    }

    return 0;
}