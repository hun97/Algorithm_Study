#include <iostream>

using namespace std;

int N;
int A[12];
int MAX = -1000000000;
int MIN = 1000000000;
int sign[4];

void solve(int depth, int ans)
{
    if (depth == N)
    {
        if (ans > MAX)
        {
            MAX = ans;
        }
        if (ans < MIN)
        {
            MIN = ans;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (sign[i] != 0)
        {
            sign[i] -= 1;
            switch (i)
            {
            case 0:
                solve(depth + 1, ans + A[depth]);
                break;
            case 1:
                solve(depth + 1, ans - A[depth]);
                break;
            case 2:
                solve(depth + 1, ans * A[depth]);
                break;
            case 3:
                solve(depth + 1, ans / A[depth]);
                break;

            default:
                break;
            }
            sign[i] += 1;
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> sign[i];
    }
    solve(1, A[0]);

    cout << MAX << endl;
    cout << MIN << endl;

    return 0;
}