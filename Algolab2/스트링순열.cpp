#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int Sum(char* str) 
{
    int sum = 0;
    int sign = 0;

    for (int i = 0; i < strlen(str); i++) {
        sign = int(pow(-1, i));
        sum += sign * int(str[i] - 'a');
    }

    return sum;
}

int permuteString(char* str, int begin, int end, int count)
{
    int range = end - begin;

    if (range == 1) {
        //cout << str << endl;

        int s = Sum(str);   // Sum 계산
        //cout << s << endl;

        if (s > 0)   // Sum이 양수인 것만 카운트
            count++;
    }
    else
    {
        for (int i = 0; i < range; i++)
        {
            swap(&str[begin], &str[begin + i]);
            count = permuteString(str, begin + 1, end, count);
            swap(&str[begin], &str[begin + i]);   /* recover */
        }
    }

    return count;
}

void permute(char* str)
{
    int c = 0;
    c = permuteString(str, 0, strlen(str), c);
    
    cout << c << endl;
}

int main(void)
{
    int numTestCase;
    cin >> numTestCase;

    char str[10] = {0x00, };
    for (int i = 0; i < numTestCase; i++) {
        cin >> str;
        permute(str);
    }

    return 0;
}