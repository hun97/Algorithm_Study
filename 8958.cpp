#include <iostream>
#include <cstring>

#define MAX_CASE 100

using namespace std;

int main(void)
{
    int N;
    int i;
    int j;
    int cnt;
    int res;
    int max;
    char str[MAX_CASE][80];
    

    i = 0;
    cin >> N;
    while (i < N)
    {
        cin >> str[i];
        i++;
    }
    i = 0;
    while (i < N)
    {
        j = 0;
        res = 0;
        cnt = 1;
        while (j < strlen(str[i]))
        {
            if (str[i][j] == 'O')
            {
                res += cnt;
                cnt++;
            }
            else
                cnt = 1;
            j++;
        }
        cout << res << endl;
        i++;
    }
    return (0);
}
