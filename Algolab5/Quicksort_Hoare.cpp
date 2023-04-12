#include <iostream>
using namespace std;

#define MAXE_SIZE   2000

int Hoare_countOP, Hoare_countCom, Lomuto_countOP, Lomuto_countCom;

void quicksort_Hoare(int A[], int low, int high);
int partition_Hoare(int a[], int low, int high);
void quicksort_Lomuto(int A[], int low, int high);
int partition_Lomuto(int a[], int low, int high);

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        Hoare_countOP = 0, Hoare_countCom = 0, Lomuto_countOP = 0, Lomuto_countCom = 0;
        int data1[MAXE_SIZE] = { 0, };
        int data2[MAXE_SIZE] = { 0, };
        cin >> num;

        for (int j = 0; j < num; j++) {
            int numdata;
            cin >> numdata;

            data1[j] = numdata;
            data2[j] = numdata;
        }

        quicksort_Hoare(data1, 0, num - 1);
        quicksort_Lomuto(data2, 0, num - 1);

        cout << Hoare_countOP << " " << Lomuto_countOP << " " << Hoare_countCom << " " << Lomuto_countCom << endl;
    }
    return 0;
}

void quicksort_Hoare(int A[], int low, int high)
{
    int p;

    if (low >= high)
        return;

    p = partition_Hoare(A, low, high);

    quicksort_Hoare(A, low, p);
    quicksort_Hoare(A, p + 1, high);
}

int partition_Hoare(int a[], int low, int high)
{
    int i, j;
    int pivot;
    
    pivot = a[low];

    i = low;
    j = high;

    while (true)
    {
        Hoare_countCom++;
        while (a[i] < pivot) {      // 비교(comparison) 연산자 ‘<’
            Hoare_countCom++;
            i = i + 1;      
        }
        Hoare_countCom++;
        while (a[j] > pivot) {      // 비교(comparison) 연산자 ‘<’
            Hoare_countCom++;
            j = j - 1;      
        }

        if (i < j) {
            Hoare_countOP++;
            swap(a[i], a[j]);      // swap 연산
            i = i + 1; j = j - 1;
        }
        else
            return j;
    }
}

void quicksort_Lomuto(int A[], int low, int high)
{
    int p;

    if (low >= high)
        return;

    p = partition_Lomuto(A, low, high);

    quicksort_Lomuto(A, low, p - 1);
    quicksort_Lomuto(A, p + 1, high);
}

int partition_Lomuto(int a[], int low, int high)
{
    int j;
    int pivot, pivot_pos;

    pivot = a[low];

    j = low;

    for (int i = low + 1; i <= high; i++) {
        Lomuto_countCom++;
        if (a[i] < pivot) {         // 비교(comparison) 연산자 ‘<’
            j = j + 1;
            Lomuto_countOP++;
            swap(a[i], a[j]);       // swap 연산
        }   
    }

    pivot_pos = j;
    Lomuto_countOP++;
    swap(a[pivot_pos], a[low]);     // swap 연산

    return pivot_pos;
}