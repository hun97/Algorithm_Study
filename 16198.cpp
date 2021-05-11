#include <iostream>
#include <vector>

using namespace std;

int N;
int ans;

void solve(vector<int> W, int sum)
{
    int n;
    n = W.size();
    if (n == 2)
    {
        if (sum > ans)
        {
            ans = sum;
        }
        return ;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int tmp = W[i - 1] * W[i + 1];
        vector<int> NW(W);
        vector<int>::iterator iter;
        iter = NW.begin();
        iter += i;
        NW.erase(iter);
        solve(NW, sum + tmp);
    }
}

int main(void)
{
    cin >> N;
    vector<int> W(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }
    solve(W, 0);
    cout << ans;
    return 0;
}