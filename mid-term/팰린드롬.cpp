#include <iostream>
using namespace std;

int pelin(int a[], int start, int end);
int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;
        int a[102];
        int check = -1;

        for (int z = 0; z < num; z++) {
            a[i] = 0;
        }

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            a[j] = data;
        }

        check = pelin(a, 0, num - 1);
        cout << check << endl;
    }
    return 0;
}

int pelin(int a[], int start, int end)
{
    if (start >= end) {
        return 1;
    }
    else {
        if (a[start] != a[end])
            return 0;
        else
            pelin(a, start + 1, end - 1);
    }
}