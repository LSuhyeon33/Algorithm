#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_SIZE    1000

void selectionSort(int a[], int n);

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int numTestCases;

    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];

        cin >> num;   // num: 정렬할 정수 개수
        for (int j = 0; j < num; j++)
            cin >> a[j];

        selectionSort(a, num);
    }

    return 0;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n)
{
    int countCmpOps = 0;   // 비교 연산자 실행 횟수
    int countSwaps = 0;   // swap 함수 실행 횟수

    // selection sort 알고리즘 구현
    for (int i = 0; i < n - 1; i++) {
        int jMin = i;

        for (int j = i + 1; j < n; j++) {
            countCmpOps++;
            if (a[jMin] > a[j])
                jMin = j;
        }

        if (jMin != i) {
            countSwaps++;
            swap(&a[jMin], &a[i]);
        }
    }
    cout << countCmpOps << " " << countSwaps << endl;
}

