#include <iostream>
using namespace std;

int Fib(int n);

int main() 
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int n;
        cin >> n;

        cout << Fib(n) << endl;
    }
    return 0;
}

int Fib(int n) 
{
    if (n <= 1)
        return n;
    else
        return Fib(n - 1) + Fib(n - 2);
}