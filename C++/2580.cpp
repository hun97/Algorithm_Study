#include <iostream>

using namespace std;

int board[9][9];
bool check_x[9][10] = {false};
bool check_y[9][10] = {false};
bool check_box[9][10] = {false};

int box_num(int i, int j)
{
    int tmp;
    tmp = (i / 3) * 3 + j / 3;
    return tmp;
}

bool solve(int cnt)
{
    if (cnt == 81)
    {
        for (int i = 0 ; i < 9 ; i++)
        {
            for (int j = 0; j < 9; j++)
            {
               cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = cnt / 9;
    int y = cnt % 9;
    if (board[x][y] != 0)
        return solve(cnt + 1);
    else
    {
        for (int k = 1; k <= 9; k++)
        {
            if (check_x[x][k] || check_y[y][k] || check_box[box_num(x, y)][k])
                continue;
            board[x][y] = k;
            check_x[x][k] = true;
            check_y[y][k] = true;
            check_box[box_num(x, y)][k] = true;
            if (solve(cnt + 1))
                return true;
            board[x][y] = 0;
            check_x[x][k] = false;
            check_y[y][k] = false;
            check_box[box_num(x, y)][k] = false;
            
        }
    }
    return false;
}

int main(void)
{
    for (int i = 0 ; i < 9 ; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            check_x[i][board[i][j]] = true;
            check_y[j][board[i][j]] = true;
            check_box[box_num(i, j)][board[i][j]] = true;
        }
    }
    solve(0);
    return 0;
}