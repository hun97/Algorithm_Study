#include <iostream>
#include <cstring>

using namespace std;

int T;
int R[1000];
char S[1000][21];

int main(void)
{
    int i;
    int j;
    int k;

    i = 0;
    cin >> T;
    while (i < T)
    {
        cin >> R[i];
        cin >> S[i];
        i++;
    }
    i = 0;
    while (i < T)
    {
        j = 0;
        while (j < strlen(S[i]))
        {
            k = 0;
            while (k < R[i])
            {
                cout << S[i][j];
                k++;
            }
            j++;
        }
        cout << endl;
        i++;
    }
    return (0);
}
