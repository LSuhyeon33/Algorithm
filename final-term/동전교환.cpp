#include <iostream>
using namespace std;

int money[7] = { 1000, 500, 100, 50, 10, 5, 1 };
int cnt;

void change(int m, int m_index)
{
    while (m >= money[0]) {
        cnt++;
        m = m - money[0];
    }
    while (m >= money[1]) {
        cnt++;
        m = m - money[1];
    }
    while (m >= money[2]) {
        cnt++;
        m = m - money[2];
    }
    while (m >= money[3]) {
        cnt++;
        m = m - money[3];
    }
    while (m >= money[4]) {
        cnt++;
        m = m - money[4];
    }
    while (m >= money[5]) {
        cnt++;
        m = m - money[5];
    }
    while (m >= money[6]) {
        cnt++;
        m = m - money[6];
    }
}

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;

        int money_index = 0;
        cnt = 0;
        
        change(m, money_index);

        cout << cnt << endl;
    }

    return 0;
}