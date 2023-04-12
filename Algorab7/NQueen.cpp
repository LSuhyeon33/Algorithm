#include <iostream>
#include <memory>
using namespace std;

int N;

void printNQ(int** board, int N) {
    int sol[17] = { 0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                sol[j] = i;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << sol[i] + 1 << " ";
    cout << endl;
}

bool isPromise(int** board, int row, int col, int N)
{
    int i, j;

    // 열 확인
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // 대각선 확인
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // 반대 대각선 확인
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool input(int** board, int col, int N)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isPromise(board, i, col, N)) {
            board[i][col] = 1;

            if (input(board, col + 1, N))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool nQueens(int row)
{
    // board 동적할당
    int** board = (int**)calloc(N, sizeof(int*));
    for (int i = 0; i < N; i++)
        board[i] = (int*)calloc(N, sizeof(int));

    if (input(board, 0, N) == false) {
        return false;
    }

    printNQ(board, N);

    // 메모리 해제
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);
    board = NULL;

    return true;
}

int main()
{
    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> N;
        nQueens(0);
    }
    return 0;
}
