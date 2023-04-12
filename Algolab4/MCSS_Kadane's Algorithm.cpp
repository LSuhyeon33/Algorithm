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
        // 1. 최대가 되는 구간이 여러 개이면 구간의 시작 index가 가장 작은 구간을 출력한다.
        // 2. 또한 같은 시작 index인 구간이 여러 개인 경우에는 가장 짧은 구간을 출력한다.
        // 이 부분에서 1번의 조건이 빠졌어요.
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

        // 먼저 시작 index부분의 값이 0인지 또는 합이 음수인지 확인
        else if (thisSum < 0 || a[j] == 0) {
            i = j + 1;
            thisSum = 0;
        }

        // 1번 조건과 2번 조건에 맞게 시작 index가 작거나 같고, 구간이 짧은 것으로 change
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