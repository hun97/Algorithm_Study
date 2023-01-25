#include <iostream>
#include <queue>

using namespace std;

int N, M;
int ans = 1;
int map[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct tomato
{
    int y, x;
};

queue<tomato> q;

int main()
{
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if ((new_x >= 0 && new_x < M) && (new_y >= 0 && new_y < N) && (map[new_y][new_x] == 0))
            {
                map[new_y][new_x] = map[y][x] + 1;
                if (ans < map[new_y][new_x])
                {
                    ans = map[new_y][new_x];
                }
                q.push({new_y, new_x});
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << (ans - 1) << endl;

    return 0;
}