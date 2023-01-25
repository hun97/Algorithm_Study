#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
string ans;
vector<char> vec;
set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

void solve(int length, int idx)
{
    if (length == l)
    {
        int cnt_v = 0;
        int cnt_c = 0;
        for (int i = 0; i < l; i++)
        {
            if (vowel.count(ans[i]) > 0)
            {
                cnt_v++;
            }
            else
                cnt_c++;
        }
        if (cnt_v >= 1 && cnt_c >= 2)
        {
            cout << ans << endl;
            return;
        }
    }
    for (int i = idx; i < c; i++)
    {
        ans.push_back(vec[i]);
        solve(length + 1, i + 1);
        ans.pop_back();
    }
}

int main()
{
    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        char c;
        cin >> c;
        vec.push_back(c);
    }

    sort(vec.begin(), vec.end());

    solve(0, 0);

    return 0;
}