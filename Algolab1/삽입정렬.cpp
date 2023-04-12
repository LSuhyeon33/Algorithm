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
/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수

    // insertion sort 알고리즘 구현
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