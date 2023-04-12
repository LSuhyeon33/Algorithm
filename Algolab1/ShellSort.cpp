#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void ShellSort(int a[], int n);

int main()
{
    int numTestCases;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE]{};
        cin >> num;

        for (int j = 0; j < num; j++)
            cin >> a[j];

        ShellSort(a, num);
    }

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Shell Sort �Լ� */
void ShellSort(int a[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��

    // Shell sort �˰��� ����
    int shrinkRatio = 2;
    int gap = n / shrinkRatio;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int tmp = a[i];
            for (int j = i; j >= gap; j -= gap) {
                countCmpOps++;
                if (a[j - gap] > tmp) {
                    countSwaps++;
                    a[j] = a[j - gap];
                }
                else
                    break;
                a[j - gap] = tmp;
            }
        }
        gap /= shrinkRatio;
    }

    cout << countCmpOps << " " << countSwaps << endl;
}