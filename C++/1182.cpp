#include <iostream>
#include <vector>

using namespace std;
int N;
int S;
int cnt;

void solve(vector<int> &arr, int idx, int sum)
{
    if (idx == N && sum == S)
    {
        cnt++;
        return ;
    }
    if (idx == N && sum != S)
        return ;
    solve(arr, idx + 1, sum + arr[idx]);
    solve(arr, idx + 1, sum);
}

int main(void)
{
    cin >> N >> S;
    vector<int> arr(N);
    for (int i; i < N ; i++)
    {
        cin >> arr[i];
    }
    solve(arr, 0, 0);
    if (S == 0)
        cnt--;
    cout << cnt;
    return (0);
}