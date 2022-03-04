#include <iostream>

using namespace std;

int row_check[15];
int check_diag1[29];
int check_diag2[29];
int cnt;
int N;

void solve(int col)
{
    int i;

    i = 0;
    if (col == N)
        cnt++;
    while (i < N)
    {
        if (!row_check[i] && !check_diag1[i - col + N - 1] && !check_diag2[i + col])
        {
            row_check[i] = 1;
            check_diag1[i - col + N - 1] = 1;
            check_diag2[i + col] = 1;
            solve(col + 1);
            row_check[i] = 0;
            check_diag1[i - col + N - 1] = 0;
            check_diag2[i + col] = 0;
        }
        i++;
    }
}


int main(void)
{
    int i;

    i = 0;
    cin >> N;
    while (i < N)
    {
        row_check[i] = 0;
        i++;
    }
    i = 0;
    while (i < (2 * N - 1))
    {
        check_diag1[i] = 0;
        check_diag2[i] = 0;
        i++;
    }
    solve(0);
    cout << cnt << endl;
    return (0);
}
