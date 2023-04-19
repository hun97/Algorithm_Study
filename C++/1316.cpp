#include <iostream>
#include <string>

#define MAX_LENGTH 100

using namespace std;

int ans = 0;

int main(void)
{
    int N;

    cin >> N;

    string word[N];

    for (int i = 0; i < N; i++)
    {
        char tmp;
        bool flag = true;
        bool check[26] = {
            0,
        };

        cin >> word[i];
        tmp = word[i][0];
        check[(int)(tmp - 'a')] = true;

        for (int j = 1; j < word[i].length(); j++)
        {
            if (tmp == word[i][j])
                continue;
            tmp = word[i][j];
            if (check[(int)(tmp - 'a')] == true)
            {
                flag = false;
                break;
            }
            else
                check[(int)(tmp - 'a')] = true;
        }

        if (flag == true)
            ans++;
    }

    cout << ans << endl;

    return (0);
}