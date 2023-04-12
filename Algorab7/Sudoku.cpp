#include <iostream>
#include <vector>
using namespace std;

int board[4][4];
int cnt;
int flag;

struct point
{
    int x, y;
};

bool check(point p)
{
    // 구역을 나눔
    int square_x = p.x / 2; 
    int square_y = p.y / 2;

    for (int i = 0; i < 4; i++)
    {
        // 같은 행에 같은 숫자가 있는 경우
        if (board[p.x][i] == board[p.x][p.y] && i != p.y)
            return false;

        // 같은 열에 같은 숫자가 있는 경우
        if (board[i][p.y] == board[p.x][p.y] && i != p.x)
            return false; 
    }

    for (int i = 2 * square_x; i < 2 * square_x + 2; i++)
        for (int j = 2 * square_y; j < 2 * square_y + 2; j++)
        {
            // 같은 구역에 같은 숫자가 있는 경우
            if (board[i][j] == board[p.x][p.y] && (i != p.x && j != p.y))
                return false; 
        }

    // 모든 조건 만족
    return true; 
}
void sudoku(int N, point points[])
{
    if (N == cnt) {
        // 스도쿠 출력
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                cout << board[i][j] << " ";
            cout << endl;
        } 
        flag = 1;
        return;
    }

    for (int j = 1; j <= 4; j++) {
        board[points[N].x][points[N].y] = j;

        // 결과가 유효하면 다음 빈칸을 채우러 감
        if (check(points[N])) {
            sudoku(N + 1, points);
            if (flag)
                return;
        }
        // 다시 0으로 되둘림
        else
            board[points[N].x][points[N].y] = 0;
    }
    flag = 0;
    return;
}
int main() 
{
    int numTestCase;
    cin >> numTestCase;

    struct point p = { 0, 0 };

    for (int k = 0; k < numTestCase; k++) {
        struct point points[17]{};
        cnt = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 0)
                {
                    p.x = i;
                    p.y = j;
                    points[cnt] = p; // 빈칸의 좌표 저장
                    cnt++;
                }
            }
        }

        sudoku(0, points);

    }
    return 0;
}