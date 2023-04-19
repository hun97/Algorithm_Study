#include <iostream>

#define MAX 3000

using namespace std;

int N;
char board[MAX][MAX];

void solve(int y, int x, int l)
{
    for (int i = (y + l / 3); i < (y + l * 2 / 3); i++)
    {
        for (int j = (x + l / 3); j < (x + l * 2 / 3); j++)
            board[i][j] = ' ';
    }
    if (l / 3 == 1)
        return;
    for (int i = y; i < (y + l); i += (l / 3))
    {
        for (int j = x; j < (x + l); j += (l / 3))
        {
            solve(i, j, l / 3);
        }
    }
}

int main(void)
{
    cin >> N;

    fill(&board[0][0], &board[N][N], '*');

    solve(0, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}