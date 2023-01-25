#include <iostream>
#include <vector>

using namespace std;

int N, ans;
int weight[11];
bool check[11];

void solve(int remain_ball, int sum)
{
    if (remain_ball == 2)
    {
        if (sum > ans)
        {
            ans = sum;
        }
        return;
    }
    for (int i = 1; i < (N - 1); i++)
    {
        if (check[i] == true)
        {
            int j, k;
            j = i;
            k = i;
            check[i] = false;
            while (!check[j])
                j--;
            while (!check[k])
                k++;
            solve(remain_ball - 1, sum + weight[j] * weight[k]);
            check[i] = true;
        }
    }
}

int main()
{
    cin >> N;
    ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
        check[i] = true;
    }

    solve(N, 0);

    cout << ans << endl;

    return 0;
}