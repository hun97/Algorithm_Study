#include <iostream>
#include <vector>

using namespace std;

vector<int> day;
vector<int> money;
int N, max_paid;

void solve(int date, int remain_day, int earned)
{
    if (date == N)
    {
        if (remain_day > 0)
        {
            return;
        }
        else if (earned > max_paid)
        {
            max_paid = earned;
            return;
        }
        else
        {
            return;
        }
    }

    if (remain_day > 0)
        solve(date + 1, remain_day - 1, earned);
    else
    {
        solve(date + 1, day[date] - 1, earned + money[date]);
        solve(date + 1, 0, earned);
    }

    return;
}

int main()
{
    int tmp1, tmp2;

    cin >> N;

    max_paid = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp1 >> tmp2;
        day.push_back(tmp1);
        money.push_back(tmp2);
    }

    solve(0, 0, 0);

    cout << max_paid << endl;

    return 0;
}