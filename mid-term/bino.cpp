#include <iostream>
using namespace std;

int binomial(int memo[], int n, int k);
int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int n, k, result;
        cin >> n >> k;
        int memo[105] = { 0, };

        result = binomial(memo, n, k);

        cout << result << endl;
    }
    return 0;
}
 
int binomial(int memo[], int n, int k)
{
    if ((k == 0) || (k == n))
        memo[k] = 1;
    else {
        if (memo[k] != 0) {
            return memo[k];
        }
        else {
            memo[k] = (binomial(memo, n - 1, k - 1) + binomial(memo, n - 1, k)) % 1000;
        }
    }
}
