#include <iostream>
using namespace std;

int Fac(int n);

int main() 
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;

        cout << Fac(num) % 1000 << endl;
    }
    return 0;
}

int Fac(int n) 
{
    if (n <= 1)
        return 1;
    else
    {
        int fac = Fac(n - 1);
        while (fac % 10 == 0)
            fac /= 10;

        int result = n * fac;
        while (result % 10 == 0)
            result /= 10;

        return result % 10000;
    }
}
