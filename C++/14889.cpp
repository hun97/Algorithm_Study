#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ans = 1000000000;
int map[21][21];
bool start_mem[21];

void solve(int depth, int idx)
{
    if (depth == N / 2)
    {
        int start;
        int link;

        start = 0;
        link = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if ((start_mem[i] == true) && (start_mem[j] == true))
                    start += map[i][j];
                if ((start_mem[i] == false) && (start_mem[j] == false))
                    link += map[i][j];
            }
        }
        int tmp = abs(start - link);
        if (ans > tmp)
        {
            ans = tmp;
        }
        return;
    }
    for (int i = idx; i < N; i++)
    {
        start_mem[i] = true;
        solve(depth + 1, i + 1);
        start_mem[i] = false;
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    solve(0, 1);

    cout << ans << endl;

    return 0;
}