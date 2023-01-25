#include <iostream>
#include <string>

using namespace std;

int M, n, bit;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    while (M--)
    {
        str.clear();
        cin >> str;

        if (str == "add")
        {
            cin >> n;
            bit |= (1 << n);
        }
        else if (str == "remove")
        {
            cin >> n;
            bit &= ~(1 << n);
        }
        else if (str == "check")
        {
            cin >> n;
            if (bit & (1 << n))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (str == "toggle")
        {
            cin >> n;
            bit ^= (1 << n);
        }
        else if (str == "all")
        {
            bit = (1 << 21) - 1;
        }
        else if (str == "empty")
        {
            bit = 0;
        }
    }

    return 0;
}