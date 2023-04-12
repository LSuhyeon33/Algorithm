#include <iostream>
using namespace std;

#define MAXSIZE     101
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int recurMax(int a[], int left, int right)
{
    int half, l, r;

    if (left == right)
        return a[left];
    else {
        half = (left + right) / 2;
        l = recurMax(a, left, half);
        r = recurMax(a, half + 1, right);
        return MAX(l, r);
    }
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        int save[MAXSIZE] = { 0, };
        cin >> num;

        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;

            save[j] = data;
        }
        
        cout << recurMax(save, 0, (num - 1)) << endl;
    }
    return 0;
}
