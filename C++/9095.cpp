#include <iostream>
#include <vector>

using namespace std;

int ans;
vector<int> vec = {1, 2, 3};

void solve(int n)
{
    if (n == 0)
    {
        ans++;
        return;
    }
    else if (n < 0)
    {
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        solve(n - vec[i]);
    }
}

int main()
{
    int T;

    cin >> T;

    while (T--)
    {
        int n;
        ans = 0;
        cin >> n;
        solve(n);
        cout << ans << endl;
    }
    return 0;
}