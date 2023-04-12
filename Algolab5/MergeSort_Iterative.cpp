#include <iostream>
using namespace std;

#define MAXE_SIZE   2000

void mergeSortIterative(int A[], int n);
void merge(int a[], int low, int mid, int high, int* count);

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        int data[MAXE_SIZE] = { 0, };
        cin >> num;

        for (int j = 0; j < num; j++) {
            int numdata;
            cin >> numdata;

            data[j] = numdata;
        }
        mergeSortIterative(data, num);
    }
    return 0;
}

void mergeSortIterative(int A[], int n)
{
    int size = 1;
    int count = 0;

    while (size < n) {
        for (int i = 0; i < n; i += 2 * size) {
            int low = i;
            int mid = low + size - 1;
            int high = min(i + 2 * size - 1, n - 1);

            if (mid >= n - 1)
                break;
            merge(A, low, mid, high, &count);
        }
        size *= 2;
    }
    cout << count << endl;
}

void merge(int a[], int low, int mid, int high, int* count)
{
    int i, j, k;
    int tmp[MAXE_SIZE] = { 0, };

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        (*count)++;
        if (tmp[i] <= tmp[j]) // <---- 핵심연산자(비교연산자)
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }
    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}

