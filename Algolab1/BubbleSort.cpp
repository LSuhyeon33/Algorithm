#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE], b[MAX_SIZE];
        cin >> num;

        for (int j = 0; j < num; j++)
            cin >> b[j];

        copyArray(a, b, num);
        bubbleSort(a, num);
        copyArray(a, b, num);
        bubbleSortImproved1(a, num);
        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        cout << endl;
    }
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* BubbleSort �Լ� */
void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��

    // bubble sort �˰��� ����
    for (int pass = 1; pass < n; pass++) {
        for (int i = 1; i <= n - pass; i++) {
            countCmpOps++;
            if (a[i - 1] > a[i]) {
                countSwaps++;
                swap(a[i - 1], a[i]);
            }
        }
    }
    cout << countCmpOps << " " << countSwaps << " ";
}

/* BubbleSort �Լ� - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��

    // bubble sort�� ������ �˰��� (1) ����
    for (int pass = 1; pass < n; pass++) {
        bool swapped = false;   // �̹� pass���� ������ ��ȯ�ߴ��� ����
        for (int i = 1; i <= (n - pass); i++) {
            countCmpOps++;
            if (a[i - 1] > a[i]) {
                countSwaps++;
                swap(a[i - 1], a[i]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    cout << countCmpOps << " " << countSwaps << " ";
}

/* BubbleSort �Լ� - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // �� ������ ���� Ƚ��
    int countSwaps = 0; // swap �Լ� ���� Ƚ��

    // bubble sort�� ������ �˰��� (2) ����
    int lastSwappedPos = n;
    while (lastSwappedPos > 0) {
        int swappedPos = 0;   // �̹� pass���� ������ ��ȯ�� ��ġ
        for (int i = 1; i < lastSwappedPos; i++) {
            countCmpOps++;
            if (a[i - 1] > a[i]) {
                countSwaps++;
                swap(a[i - 1], a[i]);
                swappedPos = i;
            }
        }
        lastSwappedPos = swappedPos;   // �̹� pass���� ��ȯ�� ������ �������� ��ġ
    }
    cout << countCmpOps << " " << countSwaps;
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}