#include <iostream>
using namespace std;

int CMM(int matrix[], int start, int end)
{
    if (start == end)
        return 0;

    int min = 2147483647;
    int count;

    for (int k = start; k < end; k++) {
        count = (CMM(matrix, start, k)
            + CMM(matrix, k + 1, end)
            + (matrix[start - 1] * matrix[k] * matrix[end]));

        if (count < min)
            min = count;
    }
    return min;
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    int mat[12] = { 0, };

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;

        for (int i = 0; i <= num; i++)
            cin >> mat[i];

        cout << CMM(mat, 1, num) << endl;
    }

    return 0;
}