#include <iostream>
using namespace std;

#define MAX_SIZE 1000
void insertionSort(int a[], int n);

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
        int a[MAX_SIZE]{};

        cin >> num;
        for (int j = 0; j < num; j++)
            cin >> a[j];

        insertionSort(a, num);
    }
    return 0;
}
/* Insertion Sort �Լ� */
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��

    // insertion sort �˰��� ����
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            countCmpOps++;
            if (a[j - 1] > a[j]) {
                countSwaps++;
                swap(&a[j - 1], &a[j]);
            }
            else
                break;
        }
    }

    cout << countCmpOps << " " << countSwaps << endl;
}