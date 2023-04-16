#include <iostream>

using namespace std;

bool check[10001] = {
    0,
};

int main(void)
{
    for (int i = 1; i <= 10000; i++)
    {
        int n = i;
        int dn = n;
        while (n > 0)
        {
            dn += n % 10;
            n /= 10;
        }
        if (dn != n && dn <= 10000)
            check[dn] = true;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (check[i] == false)
            cout << i << endl;
    }

    return (0);
}