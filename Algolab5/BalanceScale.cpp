#include <iostream>
#include <cstdlib>
using namespace std;

#define MIN(a, b)   a < b ? a : b
int weightArr[7] = { 1,2,5,10,20,50,100 };
int c[10000001];
int weight(int n);

int main()
{
    int numTestCase;
    cin >> numTestCase;

   
    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;

        // 배열 초기화
        c[0] = 0;
        for (int z = 1; z < 10000001; z++) {
            c[z] = 10000000;
        }

        int sum = 0;
        int numdata;
        cin >> numdata;
        sum += numdata;     // left is positive
        cin >> numdata;
        sum -= numdata;

        for (int j = 0; j < (num - 2); j++) {
            cin >> numdata;

            if (sum <= 0)       // negative : right
                sum += numdata;     // put left
            else       // positive : left
                sum -= numdata;     // put right
        }

        cout << weight(abs(sum)) << endl;
    }
    return 0;
}

// wg[j] = MIN(wg[j], wg[j - weightArr[i]] + 1)
int weight(int n)
{
    for (int i = 0; i < 7; i++) {
        if (weightArr[i] > n)
            break;
        for (int j = weightArr[i]; j <= n; j++)
            c[j] = MIN(c[j], c[j - weightArr[i]] + 1);
    } 
    return c[n];
}

