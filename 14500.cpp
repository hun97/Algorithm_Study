#include <iostream>

using namespace std;

int N;
int M;
int ans;
int arr[500][500];
bool check[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

void solve(int x, int y, int sum, int cnt)
{
    if (cnt == 4)
    {
        if (ans < sum)
            ans = sum;
        return ;
    }
    if (x < 0 || y < 0 || x >= N || y >= M)
        return ;
    if (check[x][y])
        return ;
    check[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        solve(x + dx[i], y + dy[i], sum + arr[x][y], cnt + 1);
    }
    check[x][y] = false;
}

int main(void)
{
    int i;
    int j;
    int tmp;

    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
             solve(i, j, 0, 0);
             if (j + 2 < M)
             {
                 if (i - 1 >= 0)
                 {
                     tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
                     if (tmp > ans)
                        ans = tmp;
                 }
                 if (i + 1 < N)
                 {
                     tmp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
                     if (tmp > ans)
                        ans = tmp;
                 }
             }
             if (i + 2 < N)
             {
                 if (j + 1 < M)
                 {
                     tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
                     if (tmp > ans)
                        ans = tmp;
                 }
                 if (j - 1 >= 0)
                 {
                     tmp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
                     if (tmp > ans)
                        ans = tmp;
                 }
             }
        }
    }
    cout << ans << endl;
    return (0);
}