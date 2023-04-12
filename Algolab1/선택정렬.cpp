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

        cin >> num;   // num: ������ ���� ����
        for (int j = 0; j < num; j++)
            cin >> a[j];

        selectionSort(a, num);
    }

    return 0;
}

/* Selection Sort �Լ� */
void selectionSort(int a[], int n)
{
    int countCmpOps = 0;   // �� ������ ���� Ƚ��
    int countSwaps = 0;   // swap �Լ� ���� Ƚ��

    // selection sort �˰��� ����
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

