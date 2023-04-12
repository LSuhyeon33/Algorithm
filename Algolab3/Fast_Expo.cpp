#include <iostream>
using namespace std;

int pow(int a, int n); 

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int a, n;
        cin >> a >> n;

        cout << pow(a, n) << endl;
    }
    return 0;
}

int pow(int a, int n)
{
    int b;

    if (n == 0)
        return 1;
    else if (n % 2 == 1) {      // n�� Ȧ���� ���
        b = (pow(a, (n - 1) / 2)) % 1000;
        return (a * b * b) % 1000;
    }
    else {      // n�� ¦���� ���
        b = (pow(a, n / 2)) % 1000;
        return (b * b) % 1000;
    }
}