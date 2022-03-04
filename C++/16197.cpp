#include <iostream>

using namespace std;

char board[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;
int N;
int M;

int solve(int cnt, int x1, int y1, int x2, int y2)
{
    bool fall1;
    bool fall2;
    fall1 = false;
    fall2 = false;
    if (cnt == 11)
        return -1;
    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M)
        fall1 = true;
    if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M)
        fall2 = true;
    if (fall1 && fall2)
        return -1;
    if (fall1 || fall2)
        return cnt;
    for (int i = 0; i < 4; i++)
    {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];
        if (0 <= nx1 && nx1 < N && 0 <= ny1 && ny1 < M && board[nx1][ny1] == '#')
        {
            nx1 = x1;
            ny1 = y1;
        }
        if (0 <= nx2 && nx2 < N && 0 <= ny2 && ny2 < M && board[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }
        int tmp = solve(cnt + 1, nx1, ny1, nx2, ny2);
        if (tmp == -1)
            continue;
        if (ans == -1)
            ans = tmp;
        if (ans > tmp)
            ans = tmp;
    }
    return ans;
}

int main(void)
{
    int x1;
    int y1;
    int x2;
    int y2;

    x1 = -1;
    cin >> N >> M;
    for (int i = 0; i < N ; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'o')
            {
                if (x1 == -1)
                {
                    x1 = i;
                    y1 = j;
                }
                else
                {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    solve(0, x1, y1, x2, y2);
    cout << ans;
    return 0;
}