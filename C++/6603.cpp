#include <iostream>
#include <vector>

using namespace std;
vector<int> lotto;

void solve(vector<int> &arr, int idx, int cnt)
{
    if (cnt == 6)
    {
        int i;
        i = 0;
        while (i < 6)
        {
            cout << lotto[i] << ' ';
            i++;
        }
        cout << '\n';
        return ;
    }
    int n = arr.size();
    if (idx == n)
        return ;
    lotto.push_back(arr[idx]);
    solve(arr, idx + 1, cnt + 1);
    lotto.pop_back();
    solve(arr, idx + 1, cnt);
} 

int main(void)
{
    int n;
    int i;
    int tmp;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<int> arr;
        i = 0;
        while (i < n)
        {
            cin >> arr[i];
            i++;
        }
        solve(arr, 0, 0);
        cout << '\n';
    }
    return (0);
}