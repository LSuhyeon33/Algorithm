#include <iostream>
using namespace std;

typedef struct Matrix_2x2 
{
    int fib[2][2];
}Matrix_2x2;

// 행렬곱: AxB=C
Matrix_2x2 multiply(Matrix_2x2 A, Matrix_2x2 B)
{
    Matrix_2x2 C;
    C.fib[0][0] = (A.fib[0][0] * B.fib[0][0] + A.fib[0][1] * B.fib[1][0]) % 1000;
    C.fib[0][1] = (A.fib[0][0] * B.fib[0][1] + A.fib[0][1] * B.fib[1][1]) % 1000;
    C.fib[1][0] = (A.fib[1][0] * B.fib[0][0] + A.fib[1][1] * B.fib[1][0]) % 1000;
    C.fib[1][1] = (A.fib[1][0] * B.fib[0][1] + A.fib[1][1] * B.fib[1][1]) % 1000;

    return C;
}

// 분할정복 기법으로 구현한 피보나치 수열 구하는 함수
/*
|F_n+1   F_n    |        |1   1 | ^ n
|F_n      F_n-1 |   =    |1   0|
*/
Matrix_2x2 Matrix_Power(Matrix_2x2 A, int n)
{
    if (n > 1) {
        A = Matrix_Power(A, n / 2);
        A = multiply(A, A);

        // n이 홀수일 경우
        if (n & 1) {
            Matrix_2x2 F = { 1, 1, 1, 0 };
            A = multiply(A, F);
        }
    }
    return A;
}
int main()
{
    int numTestCase;
    cin >> numTestCase;

    int n;
    for (int i = 0; i < numTestCase; i++) {
        cin >> n;
        Matrix_2x2 Fib = { 1,1,1,0 };

        Fib = Matrix_Power(Fib, n);
        if (n == 0)
            cout << Fib.fib[1][1] << endl;
        else
            cout << Fib.fib[0][1] << endl;
    }
    return 0;
} 
