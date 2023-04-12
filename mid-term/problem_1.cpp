#include <iostream>
using namespace std;

void searching(int a[], int start, int end);
void search(int a[], int start, int end);
int first, second;

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;
        int a[] = { 0, };
        first = 0; second = 0;

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            a[j] = data;
        }

        search(a, 0, num - 1);
        cout << second << endl;
    }
    return 0;
}

void search(int a[], int start, int end)
{
    int mid = (start + end) / 2;

    search(a, start, mid);
    search(a, mid + 1, end);
    searching(a, start, end);
}

void searching(int a[], int start, int end)
{
    for (int i = start; i <= end; i++) {
        if (a[i] > first)
            first = a[i];
        else if ((a[i] <= first) && (a[i] > second))
            second = a[i];
    }
}