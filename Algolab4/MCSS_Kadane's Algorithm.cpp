#include <iostream>
using namespace std;

#define MAXSIZE 101

int maxSubsequencesum(int a[], int n, int* start, int* end)
{
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for (i = 0, j = 0; j < n; j++) {
        thisSum += a[j];

        if (thisSum > maxSum) {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        // 1. �ִ밡 �Ǵ� ������ ���� ���̸� ������ ���� index�� ���� ���� ������ ����Ѵ�.
        // 2. ���� ���� ���� index�� ������ ���� ���� ��쿡�� ���� ª�� ������ ����Ѵ�.
        // �� �κп��� 1���� ������ �������.
        else if (thisSum == maxSum) {
            if ((j - i) < (*end - *start)) {
                maxSum = thisSum;
                *start = i;
                *end = j;
            }
            else
                continue;
        }
        else if (thisSum < 0 || a[j] == 0) {
            i = j + 1;
            thisSum = 0;
        }
    }

    /*
     if (thisSum > maxSum) {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }

        // ���� ���� index�κ��� ���� 0���� �Ǵ� ���� �������� Ȯ��
        else if (thisSum < 0 || a[j] == 0) {
            i = j + 1;
            thisSum = 0;
        }

        // 1�� ���ǰ� 2�� ���ǿ� �°� ���� index�� �۰ų� ����, ������ ª�� ������ change
        else if (thisSum == maxSum) {
            if ((i <= *start) && ((j - i) < (*end - *start))) {
                maxSum = thisSum;
                *start = i;
                *end = j;
            }
        }

    */

    return maxSum;
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        int start = 0, end = 0;
        int a[MAXSIZE] = { 0, };
        cin >> num;

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            a[j] = data;
        }

        cout << maxSubsequencesum(a, num, &start, &end) << " " << start << " " << end << endl;
    }
    return 0;
}