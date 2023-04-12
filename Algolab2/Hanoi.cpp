#include <iostream>
using namespace std;

int k;
int stack[20];

void Hanoi(int n, int a, int b, int c) 
{
    if (n > 0) {
        Hanoi(n - 1, a, c, b);
        if (c == 3) {
            cout << n << " ";
            stack[++k] = n;
        }
        if (a == 3) {
            if (k == 1) {
                k--;
                cout << 0 << " ";
            }
            else {
                cout << stack[--k] << " ";
            }
        }
        Hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    int numDisks = 0;
    for (int i = 0; i < numTestCase; i++) {
        cin >> numDisks;
        
        k = 0;
        for (int j = 0; j < 20; j++) {
            stack[j] = 0x00;
        }

        Hanoi(numDisks, 1, 2, 3);
        cout << endl;
    }

    return 0;
}