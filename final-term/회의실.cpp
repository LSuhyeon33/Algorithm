#include <iostream>
using namespace std;

int room[202];
int check[15];
int cnt;

void set(int count)
{
    int short_index = 0;
    int sh = 0;
    for (int i = 0; i < count; i++) {
        if (sh > (room[2 * i + 1] - room[2 * i])) {
            sh = room[2 * i + 1] - room[2 * i];
            short_index = 2 * i;
        }
    }

    if (isset(short_index) == 0) {
        cnt++;
        for (int i = room[short_index]; i <= room[short_index + 1]; i++) {
            check[i] = 1;
        }
    }
}

int isset(int short_index)
{
    int isset = 0;

    for (int i = room[short_index]; i <= room[short_index + 1]; i++) {
        if (check[i] == 1) {
            isset = 1;
            break;
        }
    }
    return isset;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int count;
        cin >> count;

        memset(room, 0, sizeof(int)*202);
        memset(check, 0, sizeof(int) * 15);

        for (int i = 0; i < count; i++) {
            cin >> room[2 * i] >> room[2 * i + 1];
        }

        set(count);

        cout << cnt << endl;
    }

    return 0;
}