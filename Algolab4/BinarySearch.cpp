#include <iostream>
using namespace std;

#define MAX_SIZE    102

int binarySearch(int a[], int left, int right, int value)
{
    int mid;

    if (left > right)
        return -1;
    else {
        mid = (left + right) / 2;

        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid - 1, value);
        else
            return binarySearch(a, mid + 1, right, value);
    }
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num, k;
        int a[MAX_SIZE] = { 0, };
        cin >> num >> k;

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            a[j] = data;
        }
        
        cout << binarySearch(a, 0, num - 1, k) << endl;
    }
}