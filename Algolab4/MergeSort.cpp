#include <iostream>
using namespace std;

#define MAX_SIZE    101
int c;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        c++;
        if (tmp[i] <= tmp[j]) // <---- 핵심연산자(비교연산자)
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
    }

    while (i <= mid)        // 남은 녀석을 넣어주기
        a[k++] = tmp[i++];

    while (j <= high)
        a[k++] = tmp[j++];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if (low == high)
        return;

    mid = (low + high) / 2;

    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        int a[MAX_SIZE] = { 0, };
        cin >> num;

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            a[j] = data;
        }
        c = 0;
        mergeSort(a, 0, num - 1);

        cout << c << endl;
    }
}